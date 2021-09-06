/// who.c
// Modified by Yu Jue@JY
// Modify by Yu Jue@SJ 1999-06-24
// Modified by Numa@Sj 1999-11-18 ������������ (��׼�����ˣ� bite. 4.23.2000)
// Modified by snowman@SJ 14/11/2000.  ��Ұ���Ϸʱ�����С�
// Modified by Looklove@SJ ���Ӳ鿴���߹�������
inherit F_CLEAN_UP;

#include <ansi.h>
#include <mudlib.h>
#include <net/dns.h>

mapping party=([
	"emei":       	"������",
	"zaixian":	"������Ա",
	"gaibang":    	"ؤ��",
	"gumu":       	"��Ĺ��",
	"huashan":    	"��ɽ��",
	"kunlun":   	"������",
	"mingjiao":   	"����",
	"murong":     	"����Ľ��",
	"quanzhen":   	"ȫ���",
	"shaolin":    	"������",
	"shenlong":   	"������",
	"songshan":   	"��ɽ��",
	"taohua":     	"�һ���",
	"tianlong":   	"������",
	"tiezhang":   	"���ư�",
	"wudang":     	"�䵱��",
	"xingxiu":    	"������",
	"xueshan":    	"������",
	"lingjiu":    	"���չ�",
	"xiaoyao":    	"��ң��",
	"riyue":    	"�������",
	"ouyang":    	"ŷ������",
	"on_hook":    "�һ���",
]);

int sort_user(object,object);

void create() {
	string *pname = values(party);
	int i = sizeof(pname);

	seteuid(getuid());
	while (i--) party[pname[i]] = pname[i];
}

string opt_party;

void remove_busy(object me)
{
	if (me) me->delete_temp("command_busy");
}

mixed main(object me, string arg, int remote)
{
	string str, *option, fname = "";
	object *list;
	int i, ppl_cnt, cnt, count, wcnt = 0;
        int opt_long, opt_id, opt_wiz, opt_wizall, opt_career, opt_zhuanzhan,opt_onhook;

	if (!remote) {
		if (me->query_temp("command_busy"))
			return notify_fail("����æ���ء�\n");
		me->set_temp("command_busy",1);
		call_out("remove_busy", 3, me);
	}

	opt_party = "(null)";

	if( arg ) {
		option = explode(arg, " ");
		option -= ({ "" });
		i = sizeof(option);
		while( i-- )
			switch(option[i]) {
				case "-l": opt_long = 1; break;
				case "-i": opt_id = 1; break;
				case "-wizall": opt_wizall = 1;
				case "-w": opt_wiz = 1; break;
				case "-c": opt_career = 1; break;
				case "-z": opt_zhuanzhan = 1; break;
				case "-o":	opt_onhook =1; break;
				case "-f":
				case "-p": opt_party = me->query("family/family_name"); break;
				default:
					if( option[i][0]=='@' ) {
						notify_fail("��·���鲢û�б����롣\n");
						if (find_object(DNS_MASTER) && RWHO_Q->send_rwho_q(option[i][1..<1],
							me, opt_long & wizardp(me), opt_wiz, opt_party )) {
							// ֻ�й�����Ա������ who @xx -l��Yu Jue@SJ 19990624
							write("����ѶϢ���ͳ������Ժ�\n");
							return 1;
						}
						return 0;
					}
					if (option[i][0] == '-' && !undefinedp(party[option[i][1..<1]]))
						opt_party = party[option[i][1..<1]];
					else return notify_fail("ָ���ʽ��who [-l|-i|-w|-p|-c|-o]\n");
			}
	}
/*
	if (!remote && opt_wizall && find_object(DNS_MASTER)) {
		string *mud = sort_array(keys(DNS_MASTER->query_muds()), -1);
		int m = sizeof(mud);

		while (m--) RWHO_Q->send_rwho_q(mud[m], me, 0, 1, opt_party);
	}
*/
	if( opt_long && !remote && !wizardp(me)) {
		if( (int)me->query("jing") < 50 )
			return notify_fail("��ľ���̫���ˣ�û�а취��֪������ҵ���ϸ���ϡ�\n");
		me->receive_damage("jing", 50);
	}

	str = "�� " + CHINESE_MUD_NAME + (opt_party == "(null)"?"":opt_party)
		+ "����" + (opt_wiz?"������Ա":opt_career?"����":opt_zhuanzhan?"תվ��Ա":"���") + "��\n";
	str += repeat_string("��", 40) + "\n";
	list = filter_array(children(USER_OB), (: userp($1) && environment($1) :));
	if (opt_party != "(null)" )
		list = filter_array(list, (: $1->query("family/family_name") ==
			opt_party :));
	if ( opt_career )
		list = filter_array(list, (: $1->query_temp("user_type") =="worker" :));
	
	if ( opt_onhook )
                list = filter_array(list, (: $1->query("on_hook") :));             

	if ( opt_zhuanzhan && wizardp(me) )
		list = filter_array(list, (: $1->query("bxsj_bonus/oldsj"):));

	list = sort_array(list, (: sort_user :));
	ppl_cnt = 0;
	cnt = 0;
	if( opt_long || opt_wiz ) {
		i = sizeof(list);
		while( i-- ) {
			if (remote && wizardp(list[i]) && list[i]->query("env/invisibility")) continue;
			if (!remote && !me->visible(list[i]) ) continue;
			if (opt_wiz && !wizardp(list[i]) ) continue;
			if (interactive(list[i])|| list[i]->query("on_hook")) ppl_cnt++;
			else cnt++;
			if (!wiz_level(list[i]) && fname != list[i]->query("family/family_name"))
				fname = list[i]->query("family/family_name");
			if (!wcnt && wiz_level(list[i])) {
			    wcnt = 1;
			}
			str += sprintf("%12s%s%s\n",
				RANK_D->query_rank(list[i]),
				
				interactive(list[i])?
					(query_idle(list[i]) > 120?HIM"+"NOR:" ")
                                        :(list[i]->query("on_hook")?HIR"o"NOR:HIG"*"NOR),
				
				list[i]->short(1)
			);
		}
	} else {
		string name;

		i = sizeof(list);
		count = 0;
		while( i-- ) {
			// Skip those users in login limbo.
			if (remote && wizardp(list[i]) && list[i]->query("env/invisibility")) continue;
			if (!remote && !me->visible(list[i])) continue;
			if (!wiz_level(list[i]) && fname != list[i]->query("family/family_name")) {
				fname = list[i]->query("family/family_name");
				if (count % (opt_id?4:8)) str += "\n";
				str += sprintf(HIY "%-*s" NOR, opt_id?20:10, (fname?fname:"��ͨ����") + "��");
				count = 1;
			}
			if (!wcnt && wiz_level(list[i])) {
				if (count % (opt_id?4:8)) str += "\n";
				str += sprintf(HIY "%-*s" NOR, opt_id?20:10, "������Ա��");
				wcnt = 1;
				count = 1;
			}
			name = list[i]->query("name") + (opt_id ? "("+capitalize(list[i]->query("id"))+")" : "");
			str += sprintf(" %-*s%s",
				opt_id?19:9,
				interactive(list[i])?
					(query_idle(list[i]) > 120 ? HIM"+"+name+NOR : " "+name)
                                                                        :(list[i]->query("on_hook")?HIR"o"+name+NOR:HIG"*"+name+NOR),
				
								++count % (opt_id?4:8) ? "" : "\n"
			);
			if (interactive(list[i])|| list[i]->query("on_hook")) ppl_cnt++;
			else cnt++;
		}
		if( count % (opt_id?4:8) ) str += "\n";
	}
	str += repeat_string("��", 40) + "\n";
	
	str += sprintf(
		"�� %d λ%s�����У�%d λ%s�����У�"HIR"o"NOR"��ʾ�չ��� "HIG"*"NOR" ��ʾ������  "HIM"+"NOR" ��ʾ������\n",
		ppl_cnt, opt_wiz?"������Ա":"���", cnt, opt_wiz?"������Ա":"���", query_load_average()
	);
	
	if( remote ) return str;

	me->start_more(str);
	return 1;
}

int sort_user(object ob1, object ob2)
{
	string name1, name2;
	int l1 = wiz_level(ob1), l2 = wiz_level(ob2);

	if (l1 != l2) return l2 - l1;

	if (l1) {
		name1 = ob1->query("id");
		name2 = ob2->query("id");

		if (intp(name1)) name1 = "";
		if (intp(name2)) name2 = "";
		if (name1 > name2) return -1;
		if (name1 < name2) return 1;
		return 0;
	}

	reset_eval_cost();

	name1 = ob1->query("family/family_name");
	name2 = ob2->query("family/family_name");
	if (intp(name1)) name1 = "";
	if (intp(name2)) name2 = "";
	if (name1 > name2) return -1;
	if (name1 < name2) return 1;

	l1 = ob1->query("family/generation");
	l2 = ob2->query("family/generation");
	if (l1 != l2) return l1 - l2;

	// sort by playing time.
	return ob2->query("online_total") - ob1->query("online_total");
	//return (int)ob2->query("combat_exp") - (int)ob1->query("combat_exp");
}

int help(object me)
{
	string *p;
	int i,j;

	write(@HELP
ָ���ʽ : who [-l|-i|-w|-p|-c|-Ӣ�Ĵ���]

���ָ������г����������ϵ���Ҽ���ȼ���

-l ѡ���г��ϳ���ѶϢ��
-i ֻ�г���ҵ�Ӣ�Ĵ��š�
-p ֻ�г�ͬ�ŵ���ҡ�
-f ͬ��
-w ֻ�г��������еĹ�����Ա��
-c ֻ�г����߹���
-o ֻ�г����ϱչ���Ա
-Ӣ�Ĵ��� ֻ�г������ɵ���ҡ�

HELP);
	p = sort_array(keys(party), 1);
	i = sizeof(p);
	j = i;
	write(sprintf("   %-12s%-12s    %-12s%-12s\n","Ӣ�Ĵ���","������","Ӣ�Ĵ���","������"));
	write("----------------------------------------------------------\n");
	for (i=0;i<j/2;i++)
	{
		if (i==(j/2-1))
		{
			write(sprintf("   %-10s��%-12s\n", p[i], party[p[i]]));
			continue;
		}
		if (i/2*2==i)
			write(sprintf("   %-10s��%-12s|", p[i], party[p[i]]));
		else
			write(sprintf("   %-10s��%-12s\n", p[i], party[p[i]]));
	}
	write("----------------------------------------------------------\n");
	write(@HELP

���ָ� finger
HELP);
	return 1;
}
