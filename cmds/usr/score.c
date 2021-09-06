#include <ansi.h>
#include <combat.h>

inherit F_CLEAN_UP;

string display_attr(int gift, int value);

void create() { seteuid(getuid()); }

string *age_color = ({
	CYN, YEL, HIY, HIG, HIC, HIR
});

int main(object me, string arg)
{
	object ob;
	mapping my, job;
	string line ,temp ,skill_type, title;
        int user_weapon;
	object weapon;
	int attack_points, dodge_points, parry_points;
        int canwu_exp, total_gifts, remain_gifts, yx, jihui, gongxian;
	if (!arg) ob = me;
	else if( !(ob=present(arg, environment(me))) ) {
		if (wizardp(me)) {
			if (!ob) ob = LOGIN_D->find_body(arg);
			if (!ob) ob = find_living(arg);
			if (!ob || !me->visible(ob)) return notify_fail("��Ҫ�쿴˭��״̬��\n");
		}
		else return notify_fail("��Ҫ�쿴˭��״̬��\n");
	}

	if( ob!=me && !wizardp(me) ) {
		if( userp(ob)
		  || !me->query("group/id")
		  || me->query("group/id") != ob->query("group/id")
		  || me->query("group/class") >= ob->query("group/class") )
			return notify_fail("��ֻ�ܲ鿴ͬ���ɣ��ҵȼ�����͵�NPC��״̬��\n");
	}

	my = ob->query_entire_dbase();
// add for temp title display
	my["title"] ? title = my["title"]: title = "��";
	
// ��ʾ����δ����Ļ������
        if (my["combat_exp"] < 500000) user_weapon = 0;
        else if (my["combat_exp"]  < 1000000 && !my["user_weapon_imbued"]) user_weapon = 1;
        else if ((my["combat_exp"]/1000000 - (int)my["user_weapon_imbued"])<0) user_weapon = 0;
        else if ((my["combat_exp"]/1000000 - (int)my["user_weapon_imbued"])==0) user_weapon = 1;
        else user_weapon = (my["combat_exp"]/1000000 - (int)my["user_weapon_imbued"])+1;
        user_weapon += my["imbue_reward"];
        //imbue_reward
                
	if (stringp(ob->query_temp("title")))
		title = ob->query_temp("title");

        line = "\n �q����"HIW"���齣�������Ͽ���"NOR
                +(ob->query_temp("big5")?"��":"��")+"�����ĩ����ש������������������������������������r\n";

	line += sprintf("����    ν��%-24s����  �أ���%-28s��\n",
		RANK_D->query_rank(ob),
		chinese_number(ob->query_weight()/500)+"�"
	);

	line += sprintf("��ͷ    �Σ�%-24s��%-19s%-19s��\n", title,
		"��  ������"+display_attr(my["str"], ob->query_str())+"��",
		"��  �ǣ���"+display_attr(my["con"], ob->query_con())+"��"
	);

	line += sprintf("����    ����%-24s��%-19s%-19s��\n",
		(my["color"]?my["color"]:"")+my["name"]+NOR"("+capitalize(my["id"])+")",
		"��  ������"+display_attr(my["dex"], ob->query_dex())+"��",
		"��  �ԣ���"+display_attr(my["int"], ob->query_int())+"��"
	);

	line += sprintf("����    �ţ�%-24s������������������������������������������\n",
		my["nickname"]?my["nickname"]+NOR:"��"
	);

	line += sprintf("����    �䣺%-26s��    ����%-28s��\n",
		age_color[my["day"]/5]+chinese_number(my["age"])+"��"+(my["month"]?"��"+chinese_number(my["month"])+"����":"")+NOR,
		CHINESE_D->chinese_date((my["birthday"] - 14*365*24*60) * 60)
	);

	if (objectp(weapon = ob->query_temp("weapon")) ) skill_type = weapon->query("skill_type");
	else {
		mapping prepare = ob->query_skill_prepare();

		if (!sizeof(prepare)) skill_type = "unarmed";
		else skill_type = keys(prepare)[0];
	}
	attack_points = COMBAT_D->skill_power(ob, skill_type, SKILL_USAGE_ATTACK);
	parry_points = COMBAT_D->skill_power(ob, "parry", SKILL_USAGE_DEFENSE);
	dodge_points = COMBAT_D->skill_power(ob, "dodge", SKILL_USAGE_DEFENSE);
	line += sprintf("����    ��%-26s����%-9s�㣺%-9s�ܣ�%8s��\n",
		my["gender"]+(ob->is_robot()?HIG"��������"NOR:""),
		"/cmds/std/look"->tough_level(attack_points, 0, 1),
		"/cmds/std/look"->tough_level(dodge_points, 0, 1),
		"/cmds/std/look"->tough_level(parry_points, 0, 1)
	);

	temp = ob->query("family/family_name")?"��"+my["family"]["family_name"]+"��":"����ͨ���ա�";
	temp += ob->query("family/master_name")?"��"+my["family"]["master_name"]+"��":"";
	line += sprintf("��Ǯׯ��%-26sʦ    �У�%-28s��\n",
		my["balance"]/10000?HIY BRED+chinese_number(my["balance"]/10000)+"���ƽ�"NOR:"����",
		HIW+temp+NOR
	);
		
	line += sprintf("���齣ͨ����%-64s��\n",
		my["SJ_Credit"]?HIG BGRN+chinese_number(my["SJ_Credit"])+"��"NOR:"��""",
	);


       canwu_exp    = ob->query("relife/exp_ext",1);
       total_gifts  = ob->query("relife/gifts/total",1);
       remain_gifts = ob->query("relife/gifts/now",1);

       line += sprintf("����������ȡ��%-18s�����츳��%-12sδ�����츳��%-8s��\n",
	( ob->query("relife/exp_ext"))?HBMAG"���ٷ�֮"+chinese_number(canwu_exp *5 )+"��"NOR:"��""",
	( ob->query("relife/gifts/total"))?HBRED+chinese_number(total_gifts )+"��"NOR:"��""",
        ( ob->query("relife/gifts/now")  )?HBRED+ remain_gifts +"��"NOR:"��"""

	);


	line += "�ĩ���������������������������������������������������������������������������\n";

	if (my["divorce"]) temp = "����������"+chinese_number(my["divorce"])+"��";
	else temp = "������δ��";
	if (mapp(my["marry"])) {
		if (ob->query("marry/name"))
			temp = (my["gender"]=="Ů��"?"�����"HIR:"���ޣ�"HIG)
				+my["marry"]["name"]+"("+capitalize(my["marry"]["id"])+")" NOR;
	};
	line += sprintf("��%-32s%-6s%-16d"NOR"�ۺ����ۣ�%-10d��\n",
		temp,
		my["shen"] < 0?"������"HIR:"������"HIC,
		(my["shen"] < 0?-1:1)*my["shen"],
		my["score"]
	);
                        if(ob->query("registered")<3) temp =HBCYN+HIY"������"NOR;
                              if(ob->query("registered")==3) temp =HBCYN+HIY"�¿����"NOR;
                        if(ob->query("y-card-vip")) temp =HBMAG+HIY"�꿨���"NOR;
                        if(ob->query("buyvip")) temp =HBRED+HIW "����������"NOR;
	if (base_name(ob) == "/clone/user/user") {
                line += sprintf("��ע�᣺%-16s%-10s��ʦ��%-16s��    ����%-10s��\n",
                        temp,

                        my["no_pk"]?HIY BRED"����ϴ��"NOR:""NOR,
                        my["betrayer"]?HIY+chinese_number(my["betrayer"])+"��"NOR:"��",
                        my["mana"]?HIR+ my["mana"] +"��"NOR:"��",
                );

/*

       jihui    = ob->query("skill_ext/total",1);
       yx     = ob->query("skill_ext/now",1);
       gongxian  = ob->query("party_cont",1);

	line += sprintf("��������%-26s���У�%-16sʦ�Ź��ף�%-10s��\n",
	( ob->query("skill_ext/total"))?HIY BRED"��"+chinese_number(jihui)+"�Ρ�"NOR:"��""",
	( ob->query("skill_ext/now"))?HIY BRED+chinese_number(yx)+"��"NOR:"��""",
        ( ob->query("party_cont")  )?HIY BRED+ gongxian +"��"NOR:"��"""
	);

*/
		line += sprintf("��ɱ�ˣ�%-26s��ң�%-16s����������%-10s��\n",
			my["MKS"]+my["PKS"]+my["FKS"]?HIY BBLU+chinese_number(my["MKS"] + my["PKS"] + my["FKS"])+"λ"NOR:"��",
			my["PKS"]+my["FKS"]?HIY BBLU+chinese_number(my["PKS"] + my["FKS"])+"λ"NOR:"��",
			my["FKS"]?HIY BRED+chinese_number(my["FKS"])+"λ"NOR:"��"
		);

		//��Ϊ���ţ����Լ��ϴ������.:)
                line += sprintf("��������%-26s��Ч��%-16s������᣺%-10s��\n",
                        my["death_count"]?HIM+chinese_number(my["death_count"])+"��"NOR:"��",
                        my["death_times"]?HIM+chinese_number(my["death_times"])+"��"NOR:"��",
                        user_weapon?HIM+ user_weapon +"��"NOR:"��",
                        //HIM + user_weapon + NOR
                );





		line += sprintf("���ϴ�������%-64s��\n",
			(ob->query("last_death")?ob->query("last_death"):"��δ����")
			+(ob->query("last_killer")?"��"+ob->query("last_killer")+"��":"")
		);





	}


	line += "�t���������������������������������������������������������������������������s\n";

        if (wiz_level(me)>3) {
		line += sprintf(" ��ò[%s] ��Ե[%s] ����[%s]",
			display_attr(my["per"], ob->query_per()),
			display_attr(my["kar"], ob->query_kar()),
			display_attr(my["pur"], my["pur"]));
		line += sprintf(" ����%d(+%d) ����%d ����%d(+%d)\n",
			attack_points/100, ob->query_temp("apply/damage"),
			dodge_points/100,
			parry_points/100, ob->query_temp("apply/armor"));
		if( base_name(ob) == "/clone/user/user" ){
			job = my["job_time"];
			if ( ! job) job = my;
			temp  = " �ٸ�("+(job["�ٸ�"]?job["�ٸ�"]:"��")+")";
			temp += " ����("+(job["����"]?job["����"]:"��")+")";
			temp += " ؤ��("+(job["ؤ��"]?job["ؤ��"]:"��")+")";
			temp += " ��ɽ("+(job["��ɽ"]?job["��ɽ"]:"��")+")";
			temp += " �䵱("+(job["�䵱"]?job["�䵱"]:"��")+")";
			temp += " ��ػ�("+(job["��ػ�"]?job["��ػ�"]:"��")+")\n";
			temp += " ��Ч����("+(job["��Ч����"]?job["��Ч����"]:"��")+")";
			temp += " ����("+(job["����"]?job["����"]:"��")+")";
			temp += " ������ͽ("+(job["������ͽ"]?job["������ͽ"]:"��")+")";
			temp += " ���ް���("+(job["���ް���"]?job["���ް���"]:"��")+")";
			temp += " ��ɽ("+(job["��ɽ"]?job["��ɽ"]:"��")+")";
			temp += " ѩɽ("+(job["ѩɽ"]?job["ѩɽ"]:"��")+")";
			temp += " ����("+(job["����"]?job["����"]:"��")+")\n";
			temp += " ����("+(job["����"]?job["����"]:"��")+")";
			temp += " Ľ��("+(job["Ľ��"]?job["Ľ��"]:"��")+")";
			temp += " �һ���("+(job["�һ���"]?job["�һ���"]:"��")+")";
			temp += " ץ��("+(job["ץ��"]?job["ץ��"]:"��")+")";
			temp += " ����("+(job["����"]?job["����"]:"��")+")";
			line += sprintf(" ����(����)��"+temp+"\n");
			if (my["mud_time"] >= 600) {
				line += sprintf(" ���飺%d ÿʮ���ӣ�%.1f ����ʱ�䣺%s\n",
					my["combat_exp"], my["combat_exp"]/(my["mud_time"]/600.0),
					CHINESE_D->chinese_time(my["mud_time"]/600*600)
				);
			}
		}
	}
	if (my["mud_time"] >= 86400)
		line += sprintf(" ƽ��ÿ�����ߣ�%s\n",
			CHINESE_D->chinese_time(to_int(my["mud_time"]*400.0/(time()-my["birthday"])*216)>86400?86400:to_int(my["mud_time"]*400.0/(time()-my["birthday"])*216) )
		);
	write(line);
	return 1;
}

string display_attr(int gift, int value)
{
	string str;
	if (value > gift) str = HIY;
	else if (value < gift) str = CYN;
	return str + value + NOR + "/" + gift;
;
}
int help(object me)
{
write(@HELP
ָ���ʽ : score
	   score <��������>            (��ʦר��)

���ָ�������ʾ���ָ������(��NPC)�Ļ������ϡ�

see also : hp
HELP
);
	return 1;
}
