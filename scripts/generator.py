import sys


''' This is the generator python script for generating the .launch file for n-agents.
    The script needs to be improved to accomomodate additions at a later point.
    
    TODO:
        Port to xml tree parser with some library like lxml for python.
        
'''
def main( n):
    print "<launch>"
    for i in range(0,n):
    	newbot=""
        botname="swarmbot"
        botname+=str(i) 
        newbot+="""<group ns="""
        newbot+="\"" + str(botname) + "\""
        newbot+=""">\n"""
        botID=i
        newbot+="""<param name="ID" value="""
        newbot+="\"" + str(botID) + "\""
        newbot+="""/>\n"""
        newbot+="""<param name="Agents" value="""
        newbot+="\"" + str(n) + "\""
        newbot+="""/>\n"""
        newbot+="""<param name="NAME" value="""
        newbot+="\"" + str(botname) + "\""
        newbot+="""/>\n"""
        newbot+="""<node pkg="singlerobot" type="singlerobot" name="""
        newbot+="\""+str(botname)+"\""
        newbot+=""" respawn="false" />"""
        newbot+="\n"
        newbot+="""</group>\n"""
    	print newbot
    print "</launch>"

if __name__ == '__main__':
	main(int(sys.argv[1]))
