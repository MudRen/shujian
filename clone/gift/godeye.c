
#include <ansi.h>
#include <level.h>

inherit ITEM;


void create()
{
    seteuid(getuid());
	set_name (HIY"����"NOR, ({ "godeye","eye" }));
	set("long","����һ��"HIY"����"NOR"��͸��������Բ鿴(chk)������ҵļ��ܵȼ���\n");

	set("unit","��");
	set("no_get", 1);
	set("no_drop", 1);
	set_weight(-100000);
	setup();
}

void init()
{
    seteuid(geteuid());
    add_action("do_check","chk");    
}

string *skill_level_desc = ({ LEVEL });

string *knowledge_level_desc = ({
	BLU "��ѧէ��" NOR,HIB "�����ž�" NOR,MAG "��֪һ��" NOR,HIM "��������" NOR,
	CYN "������" NOR,YEL "����С��" NOR,YEL "�ڻ��ͨ" NOR,HIY "�������" NOR,
	HIY "��Ȼ���" NOR,HIG "���д��" NOR,HIG "��ͬ����" NOR,HIC "������˫" NOR,
	HIC "������" NOR,HIW "�����ױ�" NOR,HIW "������ʥ" NOR,HIR "��ǰ����" NOR
});

string *valid_type = ({
"force", "parry",  "dodge", "unarmed","claw",
"cuff",  "finger", "strike","hand",   "leg",
"sword", "blade",  "dagger","brush",  "spear",
"hook",  "stick",  "staff", "club",   "throwing",
"whip",  "axe",    "hammer",
});

string skill_level(string, int);
int sort_skill(string sk)
{
	return (SKILL_D(sk)->type() != "martial" && SKILL_D(sk)->type() != "array");
}

int sort_basic(string sk)
{
	return member_array(sk, valid_type)!=-1;
}


string skill_level(string type, int level)
{
        int grade;
        
        switch(type) {
                case "knowledge":
                	grade = level / 20;
                        if( grade >= sizeof(knowledge_level_desc) )
                                grade = sizeof(knowledge_level_desc)-1;
                        return knowledge_level_desc[grade];
                default:
                	grade = level / 7;
                        if( grade >= sizeof(skill_level_desc) )
                                grade = sizeof(skill_level_desc)-1;
                        return skill_level_desc[grade];
        }
}

int do_check(string arg)
{
        object me,ob;
        mapping skl, lrn, map;
        string *sname, *mapped, *allskills, str = "";
        int i, j;
        int last_on = strlen(arg);
        me=this_player();
        
      
	 if(!arg)
                return notify_fail("����鿴˭��\n");           
        else{
          while (last_on--) if (arg[last_on] < 'a' || arg[last_on] > 'z')
		    {return notify_fail(arg+"��ʲô������\n");break;}
        }

	    if(!objectp(ob = LOGIN_D->find_body(arg))) {
	      ob = new(USER_OB);
	      seteuid(arg);
	      export_uid(ob);
	      ob->set_name("", ({ arg }));
	      if (!ob->restore())
            { destruct(ob); return notify_fail("û������ˡ�\n");}
	    }

	 if (wiz_level(me) < wiz_level(ob))
		return notify_fail(HIW"����ͻȻ����ҫ�۵İ׹��յ������۶���������\n"NOR);

   	 if (ob == me)
		return notify_fail("�㻹��ȥ�վ��Ӱɣ�\n");
        
        skl = ob->query_skills();
        if(!j = sizeof(skl)) {
                write(HIY"ڤڤ���㿴��"+ob->name(1)+"Ŀǰû��ѧ���κμ��ܡ�\n"NOR);
                return 1;
        }
        
        allskills  = sort_array( keys(skl), (: strcmp :) );
        
        str = HIY"ڤڤ���㿴��";
        str += ob->name(1)+"�ܹ���"+chinese_number(j)+"���";
        //if(j > 31) str+= "���Ѿ�����Ӱ�����Ժ�Ľ�����";
        str += "\n��������������������������������������������������������������������������������������������\n";
	    map = ob->query_skill_map();
        if( mapp(map) ) mapped = values(map);
        if( !mapped ) mapped = ({});

        lrn = ob->query_learned();
        if( !mapp(lrn) ) lrn = ([]);
        
        sname  = filter_array( allskills, (: sort_skill :) );
        allskills -= sname;
        
        j = sizeof(sname);
        if( j > 0){
        	str += "��"HIY"������ "+chinese_number(j)+" �֡�"NOR"��\t\t\t\t\t\t\t\t\t  ";
        	for(i=0; i < j; i++) {
        		if (i % 2 == 0) str += "��\n��";
        		str += sprintf("%s%-8s%-13s"HIC"��"NOR"%s %3d/%6d  ",
                        	(lrn[sname[i]] >= (skl[sname[i]]+1) * (skl[sname[i]]+1)) ? HIM : "",
                        	to_chinese(sname[i]), "(" + sname[i] + ")",
                        	skill_level(SKILL_D(sname[i])->type(), skl[sname[i]]),
                        	skl[sname[i]], (int)lrn[sname[i]],);
                        if ( i > j-2 && i % 2 == 0)
                        	str +="\t\t\t\t\t\t  ";
        	}
        	str += "��\n��������������������������������������������������������������������������������������������\n";
        }
        
        sname  = filter_array( allskills, (: sort_basic :) );
        allskills -= sname;
        
        j = sizeof(sname); 
        if(j > 0){
        	str += "��"HIY"������ "+chinese_number(j)+" �֡�"NOR"��\t\t\t\t\t\t\t\t\t  ";
        	for(i=0; i < j; i++) {
        		if (i % 2 == 0) str += "��\n��";
        		str += sprintf("%s%-8s%-13s"HIC"��"NOR"%s %3d/%6d  ",
                        	(lrn[sname[i]] >= (skl[sname[i]]+1) * (skl[sname[i]]+1)) ? HIM : "",
                        	to_chinese(sname[i]), "(" + sname[i] + ")",
                        	skill_level(SKILL_D(sname[i])->type(), skl[sname[i]]),
                        	skl[sname[i]], (int)lrn[sname[i]]);
                        if ( i > j-2 &&i % 2 == 0)
                        	str +="\t\t\t\t\t\t  ";
        	}
        	str += "��\n��������������������������������������������������������������������������������������������\n";
        }
        
        sname  = allskills;
        
        j = sizeof(sname);
        if(j > 0){
        	str += "��"HIY"���书 "+chinese_number(j)+" �֡�"NOR"��\t\t\t\t\t\t\t\t\t  ��\n";
        	for(i=0; i < j; i++) {
        		str += sprintf("��  %s%s%-12s%-28s" HIC "�� "NOR"%s %3d/%7d %22s\n",
                        (lrn[sname[i]] >= (skl[sname[i]]+1) * (skl[sname[i]]+1)) ? HIM : "",
                        (member_array(sname[i], mapped)==-1? "  ": "��"),
                        to_chinese(sname[i]), " (" + sname[i] + ")",
                        skill_level(SKILL_D(sname[i])->type(), skl[sname[i]]),
                        skl[sname[i]], (int)lrn[sname[i]],"��");
        	}
        	str += "��������������������������������������������������������������������������������������������\n";
        }
        
        write(str);
        if (!find_player(arg)) destruct(ob); 
        return 1;
}