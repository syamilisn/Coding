
seq = "01101011"
dict = {"00": 0, "01": 0, "10": 0, "11": 0}  #for sequences, 00, 01, 10, 11
for i in range(8):
    sub = seq[i:i+2]
    for key, val in dict.items():
        if(key == sub):
            dict[key] += 1
            
print(max(dict.values()))
