def diff(args=[]):
    try:
        if len(args) != 2 :
            print "INVALID ARGUMENTS :("
            return
        else:
            f1 = args[0]
            f2 = args[1]
            s1 = []
            s2 = []
            try:
                with open(f1,"rb") as file1:
                    s1 = file1.readlines()
            except :
                print "File 1 not found"
                return
            try:
                with open(f2,"rb") as file2:
                    s2 = file2.readlines()
            except :
                print "File 2 not found"
                return
            print "--"
            c = 0
            for i in s1:
                if i not in s2:
                    print str(c), i,
                c += 1
            print "++"
            c = 0
            for i in s2:
                if i not in s1:
                    print str(c), i,
                c += 1

    except:
        print "Error :( "

diff(["tmp/fibo_out","tmp/bin_out"])