def compare(File1,File2):
    with open(File1,'r') as f:
        d=set(f.readlines())


    with open(File2,'r') as f:
        e=set(f.readlines())

    if len(list(d-e)) == 0:
        print "Identical files"
    else:
        print "Diff is : "
        for i in list(d-e):
            print i

compare("fibo_out","bin_out")