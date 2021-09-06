// aliasd.c
string TimeDate(int t)
{
        string ts = ctime(t);
        string tm;
       // int tt;
        tm = ts[11..18];
        ts = ts[20..23]+"��"+ts[4..6]+"��"+ts[8..9]+"��";
        
        ts = replace_string(ts, " 1", "01");
        ts = replace_string(ts, " 2", "02");
        ts = replace_string(ts, " 3", "03");
        ts = replace_string(ts, " 4", "04");
        ts = replace_string(ts, " 5", "05");
        ts = replace_string(ts, " 6", "06");
        ts = replace_string(ts, " 7", "07");
        ts = replace_string(ts, " 8", "08");
        ts = replace_string(ts, " 9", "09");
        ts = replace_string(ts, "Jan", "01");
        ts = replace_string(ts, "Feb", "02");
        ts = replace_string(ts, "Mar", "03");
        ts = replace_string(ts, "Apr", "04");
        ts = replace_string(ts, "May", "05");
        ts = replace_string(ts, "Jun", "06");
        ts = replace_string(ts, "Jul", "07");
        ts = replace_string(ts, "Aug", "08");
        ts = replace_string(ts, "Sep", "09");
        ts = replace_string(ts, "Oct", "10");
        ts = replace_string(ts, "Nov", "11");
        ts = replace_string(ts, "Dec", "12");
        
        sscanf(tm,"%d:%*d:%*d",t);
        if(t<12) ts +="����ǰ";
        if(t>=12) ts +="�����";
                        
        return ts;
}

mapping global_alias = ([
	"bai":		"apprentice",
	"bei":		"prepare",
	"dating":	"check",
	"dazuo":	"exercise",
	"du":		"study",
	"fangqi":	"abandon",
	"i":		"inventory",
	"jia":		"marry",
	"jiali":	"enforce",
	"jifa":		"enable",
	"kaichu":	"expell",
	"l":		"look",
	"lian":		"practice",
	"qiu":		"propose",
	"quan":		"persuade",
	"sha":		"kill",
	"shou":		"recruit",
	"tk":		"teamkill",
	"tt":		"team talk",
	"tt*":		"team talk*",
	"tuna":		"respirate",
	"xue":		"learn",
	"yun":		"exert",
	"zisha":	"suicide",
	"chanrang":	"abdicate",
	"tanhe":	"delate",
	"fenshua":	"stucco",
	"n":		"go north",
	"e":		"go east",
	"w":		"go west",
	"s":		"go south",
	"nu":		"go northup",
	"eu":		"go eastup",
	"wu":		"go westup",
	"su":		"go southup",
	"nd":		"go northdown",
	"ed":		"go eastdown",
	"wd":		"go westdown",
	"sd":		"go southdown",
	"ne":		"go northeast",
	"se":		"go southeast",
	"nw":		"go northwest",
	"sw":		"go southwest",
	"u":		"go up",
	"d":		"go down",
	"r":		"go enter",
	"run":		"go away"
]);

string process_global_alias(string arg, object ob)
{
	string *word;
	int i;

	if (!ob)
		ob = this_player();
	if (ob && userp(ob) && !wizardp(ob) && ob->is_ghost())
		return "";
	for (i=0; i<strlen(arg); i++)
		if (arg[i] != ' ') {
			arg = arg[i..<1];
			break;
		}
	if (arg[0]=='\'')
		arg = "say " + arg[1..<1];

	word = explode(arg, " ");
	if( sizeof(word) && !undefinedp(global_alias[word[0]]) ) {
		word[0] = global_alias[word[0]];
		arg = implode(word, " ");
	}
	i = strlen(arg);
	if (ob && userp(ob) && !wizardp(ob))
		while (i--)
			if (arg[i] < ' ' && arg[i] != 27 && arg[i] != 10) arg[i] = ' ';

        if (ob && wizardp(ob) )
		write_file("/log/wiz/"+getuid(ob), ctime(time())[4..19] + arg + "\n");
	return arg;
}
