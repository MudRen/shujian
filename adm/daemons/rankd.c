// rankd.c
// optimize by Yu Jue 98.2.27
// modify by Yu Jue 99.9.8
// modify by XiaoYao 02/29/2k
// Midified by snowman@SJ 11/03/2000
// Modified by snowman@SJ 04/04/2000. added query_family_close, use by look.c
// Modified by looklove@SJ 29/04/2002

#include <ansi.h>

string query_rank(object ob)
{
	int shen = ob->query("shen");
	int budd;
	int age = ob->query("age");
	int divorce = ob->query("divorce");
	string fname;

	if (ob->is_ghost())
		return HIB "���»�Ұ��" NOR;
	if (stringp(fname = ob->query("rank_info/rank"))) {
		fname = (fname + "	")[0..7];
		switch(ob->query("rank_info/color")){
			case "BLK":return BLK "��" + fname + "��" NOR;
			case "RED":return RED "��" + fname + "��" NOR;
			case "GRN":return GRN "��" + fname + "��" NOR;
			case "YEL":return YEL "��" + fname + "��" NOR;
			case "BLU":return BLU "��" + fname + "��" NOR;
			case "MAG":return BLK "��" + fname + "��" NOR;
			case "CYN":return CYN "��" + fname + "��" NOR;
			case "WHT":return WHT "��" + fname + "��" NOR;
			case "HIR":return HIR "��" + fname + "��" NOR;
			case "HIB":return HIB "��" + fname + "��" NOR;
			case "HIM":return HIM "��" + fname + "��" NOR;
			case "HIC":return HIC "��" + fname + "��" NOR;
			case "HIW":return HIW "��" + fname + "��" NOR;
			case "HIY":return HIY "��" + fname + "��" NOR;
			default: ob->delete("rank_info/color");
				return HIG "��" + fname + "��" NOR;
		}
	}

	fname = ob->query("family/family_name");
	switch (fname) {
		case "������": budd = ob->query_skill("dacheng-fofa", 1); break;
		case "������":
		case "������": budd = ob->query_skill("buddhism", 1); break;
		case "�䵱��":
		case "ȫ���": budd = ob->query_skill("taoism", 1); break;
		case "��ɽ��":
		case "������":
    case "̩ɽ��":
    case "��ɽ��":
    case "��ɽ��":
		case "��ɽ��": budd = ob->query_skill("sword", 1); break;
		case "��Ĺ��": ob->query("gender") != "Ů��"?budd = ob->query_skill("anran-zhang", 1):budd=ob->query_skill("yinsuo-jinling", 1); break;
		case "����Ľ��": budd = ob->query_skill("shenyuan-gong", 1); break;
		case "����" :
			budd = ob->query_skill("jiuyang-shengong", 1);
			if (!budd)
				budd = ob->query_skill("shenghuo-shengong", 1);
			break;
		case "ؤ��" : budd = ob->query("gb/bags"); break;
		case "������": budd = ob->query_skill("dulong-dafa", 1); break;
		case "���ư�": budd = ob->query_skill("guiyuan-tunafa", 1); break;
		case "����": budd = ob->query_skill("qiantian-yiyang", 1); break;
		case "������": budd = ob->query_skill("huanxi-chan", 1); break;
		case "�һ���": budd = ob->query_skill("qimen-bagua", 1); break;
		case "��ң��": budd = ob->query_skill("art", 1); break;
		case "���չ�": budd = ob->query_skill("yangyanshu", 1); break;
		case "������": budd = ob->query_skill("poison", 1);	break;
		case "�������": budd = ob->query_skill("tianmo-jue", 1);	break;
		case "ŷ������": budd = ob->query_skill("poison", 1);	break;
	} // switch (fname)

	switch(ob->query("gender")) {
		case "����":
			switch(wizhood(ob)) {
				case "(admin)": return HIW "�� ��  �� ��" NOR;
				case "(assist)": return HIR "�� ��  �� ��" NOR;
				case "(arch)": return HIY "�� ��  �� ��" NOR;
				case "(wizard)": return HIG "�� ��  �� ��" NOR;
				case "(apprentice)": return HIC "�� ��  Ů ��" NOR;
				case "(immortal)": return HIC "�� ��  �� ��" NOR;
				default:
					budd = (int)ob->query_skill("pixie-jian", 1);
					if( budd >= 200) return HIR "�� ��ǧ�� ��"NOR;
					if( budd >= 180) return HIR "�� ��  �� ��"NOR;
					if( budd >= 150) return HIR "�� ��ͷ ��"NOR;
					if( budd >= 120) return HIM "������ǧ����"NOR;
					if( budd >= 90)  return MAG "�������ٻ���"NOR;
					if( budd >= 60 ) return MAG "��̫���ܹܡ�"NOR;
					if( budd >= 30 ) return MAG "�� ̫  �� ��"NOR;
					return MAG "�� С̫�� ��" NOR;
			}
		case "Ů��":
		case "����":
			switch(wizhood(ob)) {
				case "(admin)": return HIW "�� ��  �� ��" NOR;
				case "(assist)": return HIR "�� Ů��� ��" NOR;
				case "(arch)": return HIY "�� ��  Ů ��" NOR;
				case "(wizard)": return HIG "�� ��  �� ��" NOR;
				case "(apprentice)": return HIC "�� ��  �� ��" NOR;
				case "(immortal)": return HIC "�� Ů���� ��" NOR;
				default:
					if( ob->query("PKS") > 20 && ob->query("PKS") > ob->query("MKS") / 4 )
						return HIR "��ɱ��Ůħ��" NOR;
					if( (int)ob->query("thief") > 10 )
						return GRN "�� Ů���� ��" NOR;
					switch(fname) {
						case "����":
							if(budd >= 200) return HIR "�� ʥ  Ů ��" NOR;
							if(budd >= 170) return HIR "�������񼧡�" NOR;
							if(budd >= 140) return RED "�� ������ ��" NOR;
							if(budd >= 100) return RED "������������" NOR;
							if(budd >= 60) return HIM "�� Ů���� ��" NOR;
							if(budd >= 20) return CYN "�� Ů���� ��" NOR;
							return CYN "�� ��  Ů ��" NOR;
						case "ؤ��":
							if(budd >= 10) return HIW "�� ��  �� ��" NOR;
							if(budd >= 9) return HIW "�� ������ ��" NOR;
							if(budd >= 8) return HIC "�� ��  �� ��" NOR;
							if(budd >= 7) return HIG "�� ��  ͷ ��" NOR;
							if(budd >= 6) return HIM "�� Ů���� ��" NOR;
							if(budd >= 5) return HIM "�� Ů���� ��" NOR;
							if(budd >= 2) return HIM "�� Ů���� ��" NOR;
							return CYN "�� �л��� ��" NOR;
						case "������":
							if (ob->query("class") != "bonze") break;
							if (budd >= 180) return HIW "�� ��  �� ��" NOR;
							if (budd >= 140) return HIW "�� ��  �� ��" NOR;
							if (budd >= 90)  return HIW "�� ʦ  ̫ ��" NOR;
							if (budd >= 60) return HIW "�� ������ ��" NOR;
							if (budd >= 30 || age >= 20) return HIW "�� ɳ���� ��" NOR;
							return HIW "�� ѧ��Ů ��" NOR;
						case "������":
							if (budd >= 180 && shen >= 0) return HIY "�� ��ϲ�� ��" NOR;
							if (budd >= 180 && shen < 0) return HIY "�� ��ϲħ ��" NOR;
							if (budd >= 140) return HIW "�� ��  Ů ��" NOR;
							if (budd >= 90)  return HIW "�� ��  �� ��" NOR;
							if (budd >= 60) return HIW "�� Ǭ���� ��" NOR;
							if (budd >= 30 || age >= 20) return HIW "�� ����Ů ��" NOR;
							return HIW "�� ��  �� ��" NOR;
						case "��ң��":
						case "�һ���":
							if (budd >= 180) return HIW "�� ��  �� ��" NOR;
							if (budd >= 140) return HIC "�� ��  �� ��" NOR;
							if (budd >= 100) return WHT "�� ��  ʿ ��" NOR;
							if (budd >= 50 || age >= 18)  return CYN "�� ��  �� ��" NOR;
							return GRN "�� ��  Ů ��" NOR;
						case "��ɽ��":
						case "̩ɽ��":
            case "��ɽ��":
            case "��ɽ��":
						case "��ɽ��":
						case "������":
							if (budd >= 180) return HIW "�� ��  ʥ ��" NOR;
							if (budd >= 140) return HIY "�� ��  �� ��" NOR;
							if (budd >= 100) return HIC "�� Ů���� ��" NOR;
							if (budd >= 50 || age >= 18)  return YEL "�� Ů���� ��" NOR;
							return GRN "�� Ů���� ��" NOR;
						case "���չ�":
							if (budd >= 180) return HIW "�� ��  �� ��" NOR;
							if (budd >= 140) return HIY "�� �b  Ů ��" NOR;
							if (budd >= 100) return HIC "�� ��  �� ��" NOR;
							if (budd >= 50 || age >= 18)  return YEL "�� ��  Ů ��" NOR;
							return GRN "�� ��  ͯ ��" NOR;
						case "��Ĺ��":
							if (budd >= 180) return HIW "�� ��  Ů ��" NOR;
							if (budd >= 140) return HIY "�� ٻ  Ů ��" NOR;
							if (budd >= 100) return HIC "�� ��  Ů ��" NOR;
							if (budd >= 50 || age >= 18)  return YEL "�� ��  Ů ��" NOR;
							return GRN "�� ��  ͯ ��" NOR;
						case "�䵱��":
						case "ȫ���":
							if (budd >= 180) return HIY "�� ��  Ů ��" NOR;
							if (budd >= 140) return HIY "�� ��  �� ��" NOR;
							if (budd >= 100) return HIY "�� ɢ  �� ��" NOR;
							if (budd >= 50 || age >= 20) return HIY "�� ��  �� ��" NOR;
							return GRN "�� С���� ��" NOR;
						case "���ư�":
							if (budd >= 180) return WHT "�� �󵱼� ��" NOR;
							if (budd >= 140) return HIC "�� կ  �� ��" NOR;
							if (budd >= 100) return CYN "�� ��ͷĿ ��" NOR;
							if (budd >= 50 || age >= 18)  return CYN "�� ͷ  Ŀ ��" NOR;
							return GRN "�� С��� ��" NOR;
						case "������":
							if (budd >= 180) return HIB "�� ��  �� ��" NOR;
							if (budd >= 160) return YEL "�� ��  �� ��" NOR;
							if (budd >= 140) return MAG "�� ��  �� ��" NOR;
							if (budd >= 100) return BLU "�� ����ɲ ��" NOR;
							if (budd >= 50 || age >= 18)  return CYN "�� ��  �� ��" NOR;
							return GRN "�� ��ƨ�� ��" NOR;
						case "����Ľ��":
							if(budd >= 190) return HIC "�� С  �� ��" NOR;
							if(budd >= 150) return HIC "�� ׯ  �� ��" NOR;
							if(budd >= 110) return HIC "�� ��  �� ��" NOR;
							if(budd >= 70) return HIC "�� ��  �� ��" NOR;
							if(budd >= 30) return HIC "�� ��Ѿ�� ��" NOR;
							return HIC "�� Ѿ  �� ��" NOR;
							case "ŷ������":
							if(budd >= 190) return HIR "�� Ů���� ��" NOR;
							if(budd >= 150) return HIB "�� Ů��ħ ��" NOR;
							if(budd >= 110) return HIC "�� Ů�ܹ� ��" NOR;
							if(budd >= 70) return HIM "�� Ů��Ժ ��" NOR;
							if(budd >= 30) return MAG "�� Ů��� ��" NOR;
							return GRN "�� Ů�Ҷ� ��" NOR;
			        case "�������":
							if(budd >= 190) return HIR "�� ʥ  Ů ��" NOR;
							if(budd >= 150) return HIM "�� ��  �� ��" NOR;
							if(budd >= 110) return HIC "�� ��  �� ��" NOR;
							if(budd >= 70) return HIG "�� ��  �� ��" NOR;
							if(budd >= 30) return GRN "�� ��  �� ��" NOR;
							return GRN "�� ��  ͽ ��" NOR;
					} // switch(fname)

					if (!ob->query("class")) {
						if (shen >= 1500000) return HIC "��������Ů��" NOR;
						if (shen >= 1000000) return HIC "�������콿��" NOR;
						if (shen >= 500000) return HIC "������Ů����" NOR;
						if (shen >= 50000) return HIC "�� Ů���� ��" NOR;
						if (shen >= 5000) return HIC "�� Ů  �� ��" NOR;
						if (shen >= 500) return HIC "�� С��Ů ��" NOR;
						if (shen <= -1500000) return HIB "�� ��  �� ��" NOR;
						if (shen <= -1000000) return HIB "��������ɲ��" NOR;
						if (shen <= -500000) return HIB "������Ůħ��" NOR;
						if (shen <= -50000) return HIB "�� Ůħ�� ��" NOR;
						if (shen <= -5000) return HIB "�� Ůħͷ ��" NOR;
						if (shen <= -500) return HIB "�� СħŮ ��" NOR;
					}

					// û�����ɵĲŰ��������
					switch(ob->query("class")) {
						case "bonze": return GRN "�� �� �� ��" NOR;
						case "taoist":
							if (age >= 20) return GRN "�� ��  �� ��" NOR;
							return GRN "�� С���� ��" NOR;
						case "bandit": return GRN "�� Ů���� ��" NOR;
	//					case "dancer": return HIM"����ɫ���ˡ�"NOR;
						case "scholar": return GRN "�� ��  Ů ��" NOR;
						case "officer": return GRN "�� Ů  �� ��" NOR;
						case "fighter": return GRN "�� Ů���� ��" NOR;
						case "swordsman": return GRN "�� Ů��ʿ ��" NOR;
						case "alchemist": return GRN "�� Ů��ʿ ��" NOR;
						case "shaman": return GRN "�� Ů��ҽ ��" NOR;
						case "beggar": return GRN "�� �л��� ��" NOR;
						default:
							if (ob->query("marry")) {
								if (age < 30) return GRN "�� ��  �� ��" NOR;
								if (age < 50) return GRN "�����긾�ˡ�" NOR;
								return GRN "�� �ϸ��� ��" NOR;
							}
							if (divorce > 2) {
								if (age < 50) return GRN "�� ��  �� ��" NOR;
								return GRN "�� �ϵ��� ��" NOR;
							}
							if (divorce) {
								if (age < 50) return GRN "�� ��  �� ��" NOR;
								return GRN "�� �ϹѸ� ��" NOR;
							}
							if (age < 18) return GRN "�� ��  Ů ��" NOR;
							if (age < 30) return GRN "������Ů�ӡ�" NOR;
							if (age < 50) return GRN "������Ů�ӡ�" NOR;
							return GRN "�� �ϴ�Ů ��" NOR;
					} // switch(ob->query("class"))

			} // switch(wizhood(ob))
		default:
			switch(wizhood(ob)) {
				case "(admin)": return HIW "�� ��  �� ��" NOR;
				case "(assist)": return HIR "�� ��  �� ��" NOR;
				case "(arch)": return HIY "�� ��  �� ��" NOR;
				case "(wizard)": return HIG "�� ��  �� ��" NOR;
				case "(apprentice)": return HIC "�� ��  ʦ ��" NOR;
				case "(immortal)": return HIC "�� ��  �� ��" NOR;
				default:
					if (ob->query("PKS") > 20 && ob->query("PKS") > ob->query("MKS") / 4)
						return HIR "��ɱ��ħ����" NOR;
					if (ob->query("thief") > 10)
						return GRN "�� ��  �� ��" NOR;
					switch(fname) {
						case "����":
							if(budd >= 200) return HIW "�� ������ ��" NOR;
							if(budd >= 170) return WHT "������ʹ�ߡ�" NOR;
							if(budd >= 140) return HIC "�����̷�����" NOR;
							if(budd >= 100) return HIC "�����커����" NOR;
							if(budd >= 60) return HIC "�� ��  �� ��" NOR;
							if(budd >= 20) return CYN "�� ��  �� ��" NOR;
							return CYN "�� ��  �� ��" NOR;
						case "�һ���":
							if (budd >= 180) return HIW "�� ��  ʥ ��" NOR;
							if (budd >= 140) return HIC "�� ��  �� ��" NOR;
							if (budd >= 100) return WHT "�� ��  ʿ ��" NOR;
							if (budd >= 50 || age >= 18)  return CYN "�� ��  �� ��" NOR;
							return "�� ƽ  �� ��";
						case "���ư�":
							if (budd >= 180) return WHT "�� ɽ���� ��" NOR;
							if (budd >= 140) return HIC "�� կ  �� ��" NOR;
							if (budd >= 100) return CYN "�� ��  �� ��" NOR;
							if (budd >= 50 || age >= 18)  return CYN "�� ͷ  Ŀ ��" NOR;
							return "�� С��� ��";
						case "ؤ��":
							if(budd >= 10) return HIW "�� ��  �� ��" NOR;
							if(budd >= 9) return HIW "�� ������ ��" NOR;
							if(budd >= 8) return HIC "�� ��  �� ��" NOR;
							if(budd >= 7) return HIG "�� ��  ͷ ��" NOR;
							if(budd >= 6) return HIM "�� ��  �� ��" NOR;
							if(budd >= 5) return HIM "�� ��  �� ��" NOR;
							if(budd >= 2) return CYN "�� ��  �� ��" NOR;
							return CYN "�� �л��� ��" NOR;
						case "������":
							if (ob->query("class") != "bonze")
								return HIY "�� ��  �� ��" NOR;
							if (budd >= 200) return HIY "�� ��  ɮ ��" NOR;
							if (budd >= 170) return HIY "�� ʥ  ɮ ��" NOR;
							if (budd >= 120) return HIY "�� ��  �� ��" NOR;
							if (budd >= 80) return HIY "�� ��  �� ��" NOR;
							if (budd >= 60) return HIY "�� ��  �� ��" NOR;
							if (budd >= 40) return HIY "�� ��  ʦ ��" NOR;
							if (budd >= 30) return HIY "�� ��  �� ��" NOR;
							return HIY "�� ɮ  �� ��" NOR;
						case "������":
							if (ob->query("tls")) {
								if (ob->query("class") != "bonze")
									return HIY "�� ��  �� ��" NOR;
								if (budd >= 200) return HIY "�� ��  ɮ ��" NOR;
								if (budd >= 170) return HIY "�� ʥ  ɮ ��" NOR;
								if (budd >= 120) return HIY "�� ��  �� ��" NOR;
								if (budd >= 80) return HIY "�� ��  �� ��" NOR;
								if (budd >= 60) return HIY "�� ��  �� ��" NOR;
								if (budd >= 40) return HIY "�� ��  ʦ ��" NOR;
								if (budd >= 30) return HIY "�� ��  �� ��" NOR;
								return HIY "�� ɮ  �� ��" NOR;
							} else {
								if (ob->query("qinwang"))
									return HIY "�� ��  ү ��" NOR;
								if (ob->query("family/master_name")=="������")
									return HIC "�� ��  �� ��" NOR;
								if (ob->query("family/master_name")=="������")
									return HIC "�� ��  �� ��" NOR;
							}
							return HIW "�� ��  �� ��" NOR;
						case "������":
							if (budd >= 180)
								if (shen >= 0) return HIY "����ϲ������" NOR;
								else return HIY "����ϲħ����" NOR;
							if (budd >= 140) return HIY "�� ��  �� ��" NOR;
							if (budd >= 90)  return HIY "�� �󻤷� ��" NOR;
							if (budd >= 60) return HIY "�� ��  �� ��" NOR;
							if (budd >= 30 || age >= 20) return HIY "�� ��  ʿ ��" NOR;
							return HIY "�� ��  �� ��" NOR;
						case "��ɽ��":
						case "̩ɽ��":
            case "��ɽ��":
            case "��ɽ��":
						case "��ɽ��":
						case "������":
							if (budd >= 180) return HIW "�� ��  �� ��" NOR;
							if (budd >= 140) return HIY "�� ��  �� ��" NOR;
							if (budd >= 100) return HIC "�� ��  �� ��" NOR;
							if (budd >= 50 || age >= 18) return YEL "�� ��  �� ��" NOR;
							return GRN"�� ��  �� ��"NOR;
						case "���չ�":	
						case "��Ĺ��":
							if (budd >= 180) return HIW "�� ��  �� ��" NOR;
							if (budd >= 140) return HIY "�� ��  �� ��" NOR;
							if (budd >= 100) return HIC "�� ��  �� ��" NOR;
							if (budd >= 50 || age >= 18) return YEL "�� ��  �� ��" NOR;
							return GRN"�� ��  ͯ ��"NOR;
						case "��ң��":
							if (budd >= 180) return HIW "�� ��  ʥ ��" NOR;
							if (budd >= 140) return HIG "�� ��  �� ��" NOR;
							if (budd >= 100) return HIC "�� ��  �� ��" NOR;
							if (budd >= 50 || age >= 18) return HIC "�� ��  �� ��" NOR;
								return GRN "�� ��  ͯ ��" NOR;
						case "�䵱��":
						case "ȫ���":
							if (budd >= 180) return HIW "�� ��  �� ��" NOR;
							if (budd >= 140) return HIW "�� ��  ʦ ��" NOR;
							if (budd >= 100) return HIW "�� ��  �� ��" NOR;
							if (budd >= 50 || age >= 20) return HIW "�� ��  ʿ ��" NOR;
							return GRN"�� ��  ͯ ��"NOR;
						case "������":
							if (budd >= 180) return HIB "�� ��  �� ��" NOR;
							if (budd >= 160) return YEL "�� ��  �� ��" NOR;
							if (budd >= 140) return MAG "�� ��  �� ��" NOR;
							if (budd >= 100) return BLU "�� ��  �� ��" NOR;
							if (budd >= 50 || age >= 18)  return CYN "�� ��  ħ ��" NOR;
							return GRN"�� ������ ��"NOR;
						case "����Ľ��":
							if(budd >= 190) return HIC "�� ��  ү ��" NOR;
							if(budd >= 150) return HIC "�� ׯ  �� ��" NOR;
							if(budd >= 110) return HIC "�� ��  �� ��" NOR;
							if(budd >= 70) return HIC "�� ��  Ժ ��" NOR;
							if(budd >= 30) return HIC "�� ׯ  �� ��" NOR;
							return HIC "�� ׯ  �� ��" NOR;
							case "ŷ������":
							if(budd >= 190) return HIB "�� ��  �� ��" NOR;
							if(budd >= 150) return HIB "�� ��  ħ ��" NOR;
							if(budd >= 110) return HIC "�� ��  �� ��" NOR;
							if(budd >= 70) return HIM "��  ��  Ժ ��" NOR;
							if(budd >= 30) return MAG "�� ��  �� ��" NOR;
							return GRN "�� �� �� ��" NOR;
							case "�������":
							if(budd >= 190) return HIR "�� ʥ  �� ��" NOR;
							if(budd >= 150) return HIM "�� ��  �� ��" NOR;
							if(budd >= 110) return HIC "�� ��  ����" NOR;
							if(budd >= 70) return HIG "�� ��  �� ��" NOR;
							if(budd >= 30) return GRN "�� ��  �� ��" NOR;
							return GRN "�� ��  ͽ ��" NOR;
					} // switch(fname)
					if (!ob->query("class")) {
						if (shen >= 1500000) return HIC "�������񻰡�" NOR;
						if (shen >= 1000000) return HIC "������������" NOR;
						if (shen >= 500000) return HIC "������������" NOR;
						if (shen >= 50000) return HIC "�� ��  �� ��" NOR;
						if (shen >= 5000) return HIC "�� ��  �� ��" NOR;
						if (shen >= 500) return HIC "�� ��  �� ��" NOR;
						if (shen <= -15000000) return HIB "������ħ��" NOR;
						if (shen <= -1000000) return HIB "��������ħ��" NOR;
						if (shen <= -500000) return HIB "�� ħ  �� ��" NOR;
						if (shen <= -50000) return HIB "�� ħ  �� ��" NOR;
						if (shen <= -5000) return HIB "�� ħ  ͷ ��" NOR;
						if (shen <= -500) return HIB "�� ��  ħ ��" NOR;
					}
					switch(ob->query("class")) {
						case "bonze": return GRN "�� ɮ  �� ��";
						case "taoist":
							if (budd >= 50 || age >= 20) return GRN "�� ��  ʿ ��" NOR;
							return GRN "�� ��  ͯ ��" NOR;
						case "lama": return GRN "�� ��  �� ��" NOR;
						case "bandit": return GRN  "�� ��  �� ��" NOR;
						case "scholar": return GRN "�� ��  �� ��" NOR;
						case "officer": return GRN "�� ��  �� ��" NOR;
						case "fighter": return GRN "�� ��  �� ��" NOR;
						case "swordsman": return "�� ��  ʿ ��" NOR;
						case "alchemist": return GRN "�� ��  ʿ ��" NOR;
						case "shaman": return GRN "�� ��  ҽ ��" NOR;
						case "beggar": return GRN "�� �л��� ��" NOR;
						case "eunuch": return GRN "�� ̫  �� ��" NOR;
						default:
							if (ob->query("marry")) {
								if (age < 30) return GRN "���������ӡ�" NOR;
								if (age < 50) return GRN "���������ӡ�" NOR;
								return GRN "�� ��ͷ�� ��" NOR;
							}
							if (divorce > 2) {
								if (age < 50) return GRN "���������ӡ�" NOR;
								return GRN "�� ��ɫ�� ��" NOR;
							}
							if (divorce) {
								if (age < 50) return GRN "�� ��  �� ��" NOR;
								return GRN "�� ������ ��" NOR;
							}
							if (age < 18) return GRN "�� ��  �� ��" NOR;
							if (age < 30) return GRN "���������ӡ�" NOR;
							if (age < 50) return GRN "���������ӡ�" NOR;
							return GRN "�� �ϴ��� ��";
					} // switch(ob->query("class"))
			} // switch(wizhood(ob))
	} // switch(ob->query("gender"))
}

string query_respect(object ob)
{
	int age;
	string str;

	if (uptime() < ob->query_temp("rumor_show"))
		return "©��";
	if (stringp(str = ob->query("rank_info/respect")))
		return str;
	if (ob->query("race") != "����") return ob->name();

	age = ob->query("age");
	if (ob->query("gender") != "����" && ob->query_skill("beauty") > 34)
		age -= (ob->query_skill("beauty")-30)/5;
	switch(ob->query("gender")) {
		case "Ů��":
		case "����":
			switch(ob->query("class")) {
				case "bonze":
					if( age < 20 ) return "Сʦ̫";
					return "ʦ̫";
				case "huanxi":
					if( age < 20 ) return "С��Ů";
					return "Ů����";
				case "taoist":
					if( age < 20 ) return "С�ɹ�";
					return "�ɹ�";
				case "officer":
					if( age < 30 ) return "С����";
					if( age < 60 ) return "̫��";
					return "̫��";
				default:
					if( age < 20 ) return "С����";
					if( age < 50 ) return "����";
					return "����";
			}
		default:
			switch(ob->query("class")) {
				case "bonze":
					if( age < 20 ) return "Сʦ��";
					if( age < 60 ) return "��ʦ";
					return "��ʦ��";
				case "huanxi":
					if( age < 20 ) return "Сʦ��";
					return "����";
				case "officer":
					if( age < 30 ) return "�����";
					return "����";
				case "taoist":
					if( age < 20 ) return "����";
					return "����";
				case "fighter":
				case "swordsman":
					if( age < 20 ) return "С�ϵ�";
					if( age < 50 ) return "��̨";
					return "��ǰ��";
				case "eunuch": return "����";
				default:
					if( age < 20 ) return "С�ֵ�";
					if( age < 50 ) return "׳ʿ";
					return "��ү��";
			}
	}
}

string query_rude(object ob)
{
	int age;
	string str;

	if (uptime() < ob->query_temp("rumor_show"))
		return "©��";
	if (stringp(str = ob->query("rank_info/rude")))
		return str;
	if (ob->query("race") != "����")
		return "����";

	age = ob->query("age");
	if (ob->query("gender") != "����" && ob->query_skill("beauty") > 34)
		age -= (ob->query_skill("beauty")-30)/5;
	switch(ob->query("gender")) {
		case "Ů��":
		case "����":
			switch(ob->query("class")) {
				case "bonze": return "����";
				case "taoist": return "����";
				case "huanxi": return "������";
				default:
					if( age < 20 ) return "С����";
					if (age < 50) return "����";
					return "����̫��";
			}
		default:
			switch(ob->query("class")) {
				case "beggar":
					if( age < 50 ) return "��Ҫ����";
					return "��Ҫ����";
				case "bonze":
					if( age < 50 ) return "��ͺ¿";
					return "��ͺ¿";
				case "huanxi":
					if( age < 30 ) return "������";
					return "��ͺ¿";
				case "taoist": return "��ţ����";
				case "eunuch": return "����";
				default:
					if( age < 20 ) return "С���˵�";
					if( age < 50 ) return "����";
					return "��ƥ��";
			}
	}
}

string query_self(object ob)
{
	int age;
	string str;

	if (uptime() < ob->query_temp("rumor_show"))
		return "��©��";
	if (stringp(str = ob->query("rank_info/self")))
		return str;
	if (ob->query("race") != "����")
		return ob->name();

	age = ob->query("age");
	if (ob->query("gender") != "����" && ob->query_skill("beauty") > 34)
		age -= (ob->query_skill("beauty")-30)/5;
	switch(ob->query("gender")) {
		case "Ů��":
		case "����":
		switch(ob->query("class")) {
			case "bonze":
				if( age < 50 ) return "ƶ��";
				return "����";
			case "huanxi":
				if( age < 50 ) return "ƶ��";
				return "����";
			case "officer":
				if( age < 50 ) return "�¹�";
				return "����";
			default:
				if( age < 30 ) return "СŮ��";
				return "���";
		}
		default:
			switch(ob->query("class")) {
				case "huanxi":
					if( age < 30 ) return "������";
					return "����ү";
				case "beggar":
					if( age < 30 ) return "���л�";
					return "�Ͻл�";
				case "bonze":
					if( age < 50 ) return "ƶɮ";
					return "����";
				case "taoist":
					return "ƶ��";
				case "eunuch": return "����";
				case "officer":
					if( age < 50 ) return "�¹�";
					return "����";
				default:
					if( age < 50 ) return "����";
					return "��ͷ��";
			}
	}
}

string query_self_rude(object ob)
{
	int age;
	string str;

	if (uptime() < ob->query_temp("rumor_show"))
		return "©����";
	if( stringp(str = ob->query("rank_info/self_rude")) )
		return str;
	if(ob->query("race") != "����")
		return ob->name() + "��";

	age = ob->query("age");
	if (ob->query("gender") != "����" && ob->query_skill("beauty") > 34)
		age -= (ob->query_skill("beauty")-30)/5;
	switch(ob->query("gender")) {
		case "Ů��":
		case "����":
		switch(ob->query("class")) {
			case "bonze":
				if (age < 50) return "ƶ����";
				return "������";
			case "huanxi":
				if (age < 50) return "ƶ��";
				return "����";
			case "officer":
				if( age < 30 ) return "����";
				return "̫��";
			default:
				if (age < 20) return "��С��";
				if (age < 50) return "������";
				return "������";
		}
		default:
			switch(ob->query("class")) {
				case "bonze":
					if( age < 50 ) return "�������";
					return "�Ϻ�����";
				case "hunxi":
					if( age < 30 ) return "��������";
					return "����ү��";
				case "officer":
					if( age < 30 ) return "����ү��";
					return "̫ү��";
				case "taoist":
					return "��ɽ����";
				case "eunuch": return "������";
				default:
					if( age < 50 ) return "��ү��";
					return "����";
			}
	}
}

string query_family_close(object me, object ob)
{
	mapping fam, my_fam;

	if (ob == me)
		return "����";

	if (!mapp(fam = ob->query("family"))
	|| !mapp(my_fam = me->query("family"))
	|| fam["family_name"] != my_fam["family_name"]){
		if( me->query("age") > ob->query("age") +10)
			return "��";
		if( me->query("age") +10 < ob->query("age") )
			return "ǰ��";
		return "ͬ��";
	}

	if (fam["generation"] == my_fam["generation"]) {
		if( (string)ob->query("gender") == "Ů��")
			return my_fam["enter_time"] > fam["enter_time"]?"ʦ��":"ʦ��";
		return my_fam["enter_time"] > fam["enter_time"]?"ʦ��":"ʦ��";
	 }

	 if (fam["generation"] < my_fam["generation"]) {
		if (my_fam["generation"] - fam["generation"] == 1) {
			if (my_fam["master_id"] == ob->query("id"))
				return "ʦ��";
			return fam["enter_time"] < my_fam["enter_time"]?"ʦ��":"ʦ��";
		}

		if (my_fam["generation"] - fam["generation"] == 2)
			return fam["enter_time"] < my_fam["enter_time"]?"ʦ����":"ʦ����";

		if (my_fam["generation"] - fam["generation"] == 3)
			return fam["enter_time"] < my_fam["enter_time"]?"��ʦ��":"��ʦ��";

		return fam["enter_time"] < my_fam["enter_time"]?"̫ʦ��":"̫ʦ��";
	}

	if (fam["generation"] - my_fam["generation"] == 1) {
		if (fam["master_id"] == me->query("id"))
			return "����";
		return "ʦֶ";
	}

	if (fam["generation"] - my_fam["generation"] == 2)
		return "ͽ��";

	if (fam["generation"] - my_fam["generation"] == 3)
		return "��ͽ��";

	return "̫ͽ��";
}

string query_close(mixed ob, object me)
{
	mixed a1, a2;
	string ob_gender;
	
	if (!me) me = this_player();
	if (objectp(ob)) {
		if ((a1 = me->query("family/family_name"))
		&& a1 == ob->query("family/family_name"))
			return query_family_close(me, ob);
		if (a2 = ob->query("age") * 12 + ob->query("month"))
			a1 = me->query("age") * 12 + me->query("month");
		else {
			a1 = me->query("mud_age");
			a2 = ob->query("mud_age");
		}
	} else {
		a1 = me->query("age") * 12 + me->query("month");
		a2 = 0;
	}

	if (objectp(ob)) 
		if (ob->query("gender") != "����" && ob->query_skill("beauty") > 30)
			a2 -= (ob->query_skill("beauty")-30)/5*12;

	if (me->query("gender") != "����" && me->query_skill("beauty") > 30)
		a1 -= (me->query_skill("beauty")-30)/5*12;
	
	if(objectp(ob)) ob_gender = ob->query("gender");
	else ob_gender = ob["gender"];
	
	if(!objectp(ob)) a2 = ob["age"];
	
	switch (ob_gender) {
		case "Ů��" :
		case "����" :
			if (objectp(ob) && userp(ob) && ob->query("id") == me->query("marry/id"))
				return "����";
			if (a2 - a1 >= 240)
				return "�ù�";
			if (a1 - a2 >= 240)
				return "ֶŮ";
			if (a1 > a2)
				return "����";
			return "���";
			break;
		default :
			if (objectp(ob) && userp(ob) && ob->query("id") == me->query("marry/id"))
				return "�๫";
			if (a2 - a1 >= 240)
				return "����";
			if (a1 - a2 >= 240)
				return "ֶ��";
			if (a1 > a2)
				return "�͵�";
			return "���";
	}
}

string query_self_close(mixed ob, object me)
{
	int a1, a2;

	if (!me)
		me = this_player();
	if (objectp(ob)) {
		if ((a1 = me->query("family/family_name"))
		&& a1 == ob->query("family/family_name"))
			return query_family_close(ob, me)+"��";
		if (a2 = ob->query("age") * 12 + ob->query("month"))
			a1 = me->query("age") * 12 + me->query("month");
		else {
			a1 = me->query("mud_age");
			a2 = ob->query("mud_age");
		}
	} else {
		a1 = me->query("age") * 12 + me->query("month");
		a2 = 0;
	}
	
	if (objectp(ob))
	if (ob->query("gender") != "����" && ob->query_skill("beauty") > 30)
		a2 -= (ob->query_skill("beauty")-30)/5*12;
	if (me->query("gender") != "����" && me->query_skill("beauty") > 30)
		a1 -= (me->query_skill("beauty")-30)/5*12;
		
	if(!objectp(ob)) a2 = ob["age"];

	switch (me->query("gender")) {
		case "Ů��" :
		case "����" :
			if (objectp(ob) && userp(ob) && ob->query("id") == me->query("marry/id"))
				return "�����";
			if (a1 - a2 >= 240) return "�ù���";
			if (a2 - a1 >= 240) return "ֶŮ��";
			if (a1 > a2) return "�����";
			return "С����";
			break;
		default :
			if (objectp(ob) &&userp(ob) && ob->query("id") == me->query("marry/id"))
				return "�޷���";
			if (a1 - a2 >= 240) return "������";
			if (a2 - a1 >= 240) return "Сֶ��";
			if (a1 > a2) return "������";
			return "С����";
	}
}
