#!/usr/bin/python
#################################################
#  tarantula.py: implement tarantula algorithm	#
# 	Jessica Calnan				#
#   Extra Credit - Due: 12/8/17			#
#################################################

def main():
 
    data = {}
 
    total_metadata = analyze('analysis.txt')
    for metadata in total_metadata:
        gcov_proc(metadata, data)

    suspicious_rank(total_metadata, data)

    for item in data:
        if data[item]['susp'] > 0.6:
            print('item #' + str(item) + ' has a suspicious rating of ' +
                   str(data[item]['susp']) + ':')
            print('\t' + data[item]['code'] + '\n')


def suspicious_rank(meta, data):
    """
    Determines the suspiciousness of each element
    """
    failing = sum([1 for x in meta if x['status'] == 'fail'])
    passing = sum([1 for x in meta if x['status'] == 'pass'])
    for item in data:
        try:
            percent_fail = float(data[item]['fail']) / (failing)
        except ZeroDivisionError:
            percent_fail = 0
            
        try:
            percent_pass = float(data[item]['pass']) / (passing)
        except ZeroDivisionError:
            percent_pass = 0

        susp = percent_fail / (percent_pass + percent_fail)
        data[item]['susp'] = susp


def gcov_proc(meta, data):
    """
    Runs a gcov file, returns analysis.  Processes 'meta' and produces 'data'.
    """
    with open(meta['filepath']) as file:
        for item in file:
            list = item.strip().split(':')
            if list[0] == '-':
                continue
         
            line_info = {}
            line_info['lineNum'] = int(list[1].strip())
            line_info['code'] = list[2].strip()
            line_info['raw'] = item.strip('\n')

            try:
                line_info['run_amt'] = int(list[0].strip())
            except:
                line_info['run_amt'] = 0

            if line_info['run_amt'] == 0:
                try:
                    data[line_info['lineNum']][meta['status']] += 1
                except KeyError:
                    data[line_info['lineNum']]= {'pass': 0, 'fail': 0, 'code': line_info['code']}
                    data[line_info['lineNum']][meta['status']] = 1


def analyze(in_file):
    """
    Analysis file shows names, files, and whether pass or fail.
    """
    with open(in_file) as file:
        analysis_file = []
        for item in file:
            info = {}

            i = item.split()
            info['name']    = i[0]
            info['path'] = i[1]
            info['status']   = i[2]
            
            analysis_file.append(info)

    return analysis_file

if __name__ == '__main__':
    main()
