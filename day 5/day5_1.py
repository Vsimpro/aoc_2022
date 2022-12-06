# AoC Day 5a
# After the rearrangement procedure completes, 
# what crate ends up on top of each stack?
instructions = []
storage_arrangment = {
    1: [],
    2: [],
    3: [],
    4: [],
    5: [],
    6: [],
    7: [],
    8: [],
    9: []
}
read_state = "storage_arrangment"

#Read the input
for line in open("input.txt"):
    if ("1  ") in line: read_state = "instructions"; continue;
    if (line == ""): continue

    if (read_state == "instructions" and line != ''):
        if "" == line or "\n" == line: continue

        amount = int(line.split(" from ")[0].replace("move ", ""))
        start  = int(line.split(" from ")[1].split(" to ")[0])
        end_up = int(line.split(" from ")[1].split(" to ")[1])
        
        for i in range(0, amount):
            container = storage_arrangment[start][0]
            
            del storage_arrangment[start][0]
            
            storage_arrangment[end_up][0:0] = container
    
    # Parse arrangment into storage
    for i in range(1,10):
        # Each container is 4 indexes apart;
        # First one beginning with spot 2 (index 3).
        # -> (i * 4) - 3 = container.
        try:
            container = line[(i*4) - 3]
            if container != " ": storage_arrangment[i].append(container)

        except Exception as e:
            continue

for key in storage_arrangment:
    try:
        print(storage_arrangment[key][0], end="")
    except IndexError:
        pass