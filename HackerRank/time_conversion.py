#
# Complete the timeConversion function below.
#
def timeConversion(s):
    hh_pos = s.find(':')
    hh = s[0:hh_pos]
    if s.find('AM') > -1:
        if hh == '12':
            return ''.join(['00', s[hh_pos:-2]])
        return s[:-2]
    else:
        if hh == '12':
            return s[:-2]
        hh_int = int(hh) + 12
        return ''.join([str(hh_int), s[hh_pos:-2]])