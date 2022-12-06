_sum = 0; # i got fed up with c++ 
for line in [line.strip() for line in open("input.txt")]: 
    duplicates = [];  # So I had to release some bent up anger by creating this monstrosity.
    for item in line[0:int(len(line)/2)]: _sum += (item in  line[int(len(line)/2):int(len(line))] and item not in duplicates) * ("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ".find(item) + 1); duplicates.append((item in line[int(len(line)/2):int(len(line))] and item not in duplicates)  * item)

print(_sum) # I'm sorry.