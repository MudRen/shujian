
#include <ansi.h>
#include <level.h>

inherit ITEM;


void create()
{
	seteuid(ROOT_UID);
	set_name (HIC"���֮ͫ"NOR, ({ "skyeye","eye" }));
	set("long","����һ��"HIC"���֮ͫ"NOR"�������͸���鿴(chk)�Ϳ���(peek)������ҡ�\n");

	set("unit","��");
	set("no_get", 1);
	set("no_drop", 1);
	set_weight(-100000);
	setup();
}

void init()
{
    seteuid(ROOT_UID);
    add_action("do_peek","peek");
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
                return notify_fail("����鿴�ĸ�˭��\n");           
        else{
          while (last_on--) if (arg[last_on] < 'a' || arg[last_on] > 'z')
		    {return notify_fail(arg+"��ʲô������\n");break;}
        }

	    if(!objectp(ob = LOGIN_D->find_body(arg))) {
	      ob = new(USER_OB);
	      seteuid(arg);
	      export_uid(ob);
	      seteuid(getuid());
	      ob->set_name("", ({ arg }));
	      if (!ob->restore())
            { destruct(ob); return notify_fail("û������ˡ�\n");}
	    }

  	 if (wiz_level(me) < wiz_level(ob))
		return notify_fail(HIC"���֮ͫͻȻ����ҫ�۵������յ������۶���������\n"NOR); 	

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

string status_color(int current, int max);

string conv(int i)
{
	if (i < 1000) return ""+i;
	return conv(i/1000)+sprintf(",%03d", i%1000);
}

int do_peek(string arg)
{
	object me=this_player(),ob;
	int lmt, i;
	mapping my;
    int last_on = strlen(arg);
    //string dinfo;      
	

       if(!arg)
                return notify_fail("��������ĸ���ҡ�\n");           
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
        { destruct(ob); return notify_fail("û�������ҡ�\n");}
	}

   	if (ob == me)
		return notify_fail("�㻹��ȥ�վ��Ӱɣ�\n");

	if (ob->is_corpse() || !ob->is_character())
		return notify_fail("�ǲ��ǻ���Ү��\n");
	
	if (wiz_level(me) < wiz_level(ob))
		return notify_fail(HIC"���֮ͫͻȻ����ҫ�۵������յ������۶���������\n"NOR); 	
	
	my = ob->query_entire_dbase();

	if (userp(ob)){
		lmt = my["combat_exp"];
		for (i = to_int(pow(10.0 * lmt, 0.3333333));to_int(i*i/10.0*i)<=lmt;i++);
		my["max_pot"] = i+100;
	}

	if (!my["max_jing"]) my["max_jing"] = 1;
	if (!my["max_qi"]) my["max_qi"] = 1;
	write(HIY"ڤڤ���㿴����"+ob->name(1)+"��״̬"NOR); 
	write(sprintf("\n����Ѫ��%s%5d / %5d %s(%3d%%)" NOR "  ��������%s%5d / %5d%s(%d)\n" NOR,
		status_color(my["jing"], my["eff_jing"]+ob->query_temp("apply/jing")), my["jing"], my["eff_jing"]+ob->query_temp("apply/jing"),
		status_color(my["eff_jing"]+ob->query_temp("apply/jing"), my["max_jing"]), ((my["eff_jing"]+ob->query_temp("apply/jing")) * 100 / my["max_jing"]),
		status_color(my["jingli"], my["eff_jingli"]+ob->query_temp("apply/jingli")), my["jingli"], my["eff_jingli"]+ob->query_temp("apply/jingli"),
		status_color(my["jingli"], my["eff_jingli"]+ob->query_temp("apply/jingli")), my["eff_jingli"]-my["max_jingli"]+ob->query_skill("force")*8 ));
	write(sprintf("����Ѫ��%s%5d / %5d %s(%3d%%)" NOR "  ��������%s%5d / %5d(+%d)\n" NOR,
		status_color(my["qi"], my["eff_qi"]+ob->query_temp("apply/qi")), my["qi"], my["eff_qi"]+ob->query_temp("apply/qi"),
		status_color(my["eff_qi"]+ob->query_temp("apply/qi"), my["max_qi"]), ((my["eff_qi"]+ob->query_temp("apply/qi")) * 100 / my["max_qi"]),
		status_color(my["neili"], my["max_neili"]+ob->query_temp("apply/neili")), my["neili"], my["max_neili"]+ob->query_temp("apply/neili"),
		my["jiali"] ));

	write(sprintf("��%s����%s %-13s   " NOR " ���������ޡ�"HIC"%5d / %5d\n" NOR,
		my["shen"] < 0?"��":"��",
		my["shen"] < 0?HIR:HIC,
		conv((my["shen"] < 0?-1:1) * my["shen"]),
		(ob->query_skill("force")-ob->query_temp("apply/force"))*8 + my["combat_exp"]/1000 + ob->query_temp("apply/neili"),
		(ob->query_skill("force")-ob->query_temp("apply/force"))*10 + my["age"]*20 + my["combat_exp"]/1000 + ob->query_temp("apply/neili")));

	i = ob->max_food_capacity();
	if (!i) i = 1;
	write(sprintf("��ʳ�%s%7.2f%%	 " NOR "     ��Ǳ�ܡ�"HIY" %4d / %4d\n" NOR,
		status_color(my["food"], i),
		my["food"]*100.0/i, my["potential"], my["max_pot"] ));
	i = ob->max_water_capacity();
	if (!i) i = 1;
	write(sprintf("����ˮ��%s%7.2f%%	 " NOR "     �����顤"HIM" %s\n"NOR,
		status_color(my["water"], i),
		my["water"]*100.0/i,
		conv(ob->query("id") == "zhong shentong"?my["combat_exp"]/3*2:my["combat_exp"])));
       if (!find_player(arg)) destruct(ob);
	return 1;
}

string status_color(int current, int max)
{
	int percent;

	if( max ) percent = current * 100 / max;
	else percent = 0;
	if( percent > 100 ) return HIC;
	if( percent >= 90 ) return HIG;
	if( percent >= 60 ) return HIY;
	if( percent >= 30 ) return YEL;
	if( percent >= 10 ) return HIR;
	return RED;
}
