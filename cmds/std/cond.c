// test.c

inherit F_CLEAN_UP;
#include <ansi.h>

#define		CON_DIR		"/kungfu/condition/"

string get_con_name(string coni)
{
	string name;
	
	switch (coni)
	{
		// ����
		case "7bug_poison"	: name = "�߳����ɢ"; break;		
		case "bee_poison"	: name = "��䶾"; break;
		case "bing_poison"	: name = "�������붾"; break;
		case "bt_poison"	: name = "���߶�"; break;		
		case "cold_poison"	: name = "����"; break;
		case "fs_poison"	: name = "��ʬ��"; break;
		case "hb_poison"	: name = "�������ƶ�"; break;		
		case "huagu_poison"	: name = "�������ƶ�"; break;
		case "hot_poison"	: name = "��"; break;	
		case "lvbo_poison"	: name = "�̲���¶�涾"; break;						
		case "man_poison"	: name = "�����ܻ���"; break;
		case "qianli_poison"	: name = "ǧ������ɢ"; break;
		case "qtlh_poi"		: name = "�����޻���"; break;
		case "qzhu_poison"	: name = "ǧ�����ֶ�"; break;
		case "sanxiao"		: name = "��Ц��ңɢ��"; break;
		case "sl_poison"	: name = "������"; break;
		case "snake_poison"	: name = "�߶�"; break;	
		case "sxs_poison"	: name = "��Цɢ֮��"; break;	
		case "sy_poison"	: name = "����ӡ�ƶ�"; break;	
		case "tz_poison"	: name = "���ƶ�"; break;		
		case "warm_poison"	: name = "�ȶ�"; break;
		case "xx_poison"	: name = "�����ƶ�"; break;
		case "wh_poison"	: name = "�������ж�"; break;	
			
		case "xuanmin_poison"	: name = "��ڤ���ƺ���"; break;
		case "xx_poison"	: name = "�����ƶ�"; break;
		case "wh_poison"	: name = "�������ж�"; break;	
		
		// ����
		case "broken_arm"	: name = "����"; break;
		case "dgb_ban_wound"	: name = "�򹷰�����"; break;
		case "fugu_poison"	: name = "��Ѫ���Ƿ�"; break;
		case "dsy_poison"	: name = "����ӡ����"; break;		
		case "huagong"		: name = "����������"; break;		
		case "hunyuan_hurt"	: name = "��Ԫ������"; break;
		case "hyd_condition"    : name = "���浶����"; break;
		case "juehu_hurt"	: name = "��צ��������"; break;
		case "neishang"		: name = "����"; break;
		case "nxsz_hurt"	: name = "��Ѫ��צ����"; break;
		case "qiankun_wound"	: name = "��ָ��ͨ����"; break;
		case "qishang_poison"	: name = "����ȭ����"; break;
		case "ruanjin_poison"	: name = "���ɢ��"; break;
		case "yyz_hurt"		: name = "һ��ָ����"; break;
		case "yzc_qiankun"	: name = "һָ���ھ�"; break;		
		// æ��
		case "no_exert"		: name = "����"; break;
		case "no_perform"	: name = "����"; break;
		case "no_force"		: name = "��Ϣ����";break;
		//������
		case "ill_fashao"	: name = "����"; break;
		case "ill_kesou"	: name = "����"; break;
		case "ill_shanghan"	: name = "�˺�"; break;
		case "ill_zhongshu"	: name = "����"; break;
		case "ill_dongshang"	: name = "����"; break;		
//		// ҩ��
//		case "bonze_drug"	: name = "���ֵ�ҩ"; break;
//		
//		// ����
//		case "bonze_jail"	: name = "���ּ���"; break;
		case "job_busy"		: name = "����æ״̬"; break;
		case "gb_job_busy"		: name = "��Ħ�����񵹼�ʱ"; break;
		case "qzkj_job_busy"		: name = "ȫ�濹�𵹼�ʱ"; break;
		case "xykm_job_busy"		: name = "�������ɵ���ʱ"; break;
                case "hb_job_busy"           : name = "�����ھֻ��ڵ���ʱ"; break;
              case "lfta_job"               : name = "����Ϯ��"; break;
              case "zwf_job_busy"               : name = "ҹ̽������"; break;
               case "db_exp"               : name = "˫������"; break;
               case "xs_job"               : name = "ѩɽǿ����Ů"; break;
               case "gifts"               : name = "�츳"; break;
               	
case "fuben"               : name = "����"; break;
                default                 : name = "����"; break;
	}
	
	return name;
}

int main(object me,string arg)
{
	object tar, conob;
	int i, p, h, b, m, d;
	string msg, coni, conn, contp,cont;
	mapping cons;
	
	
	
        if (!userp(me)) return 0;
        	seteuid(getuid(me));

        if (!arg) tar = me;
        else if (!objectp(tar = present(arg, environment(me)))) {
                if (wizardp(me) ) {
                        if (!tar) tar = LOGIN_D->find_body(arg);
                        if (!tar) tar = find_living(arg);
                        if (!tar) return notify_fail("��Ҫ�쿴˭������״̬��\n");
                        if (wiz_level(me) < wiz_level(tar))
                                return notify_fail("��Ҫ�쿴˭������״̬��\n");
                }
        }

        if (!wizardp(me) && me!=tar)
                return notify_fail("��Ҫ�쿴˭������״̬��\n");

        if (tar->is_corpse() || !tar->is_character())
                return notify_fail("�ǲ��ǻ���Ү��\n");
		
//		if ( sizeof(tar->query_entire_conditions()) < 1 )
//		{
//			tell_object(me, (tar!=me?tar->name(1):"��")+"����û�а����κ�����״̬��\n");
//			return 1;
//		}

		msg = (tar!=me?tar->name(1):"��")+"���ϰ�����������״̬��\n";
		msg += "����������������������������������������������������
��״̬���ƣ���������Լʣ��ʱ�䣠��������      ���
����������������������������������������������������\n";

		cons = tar->query_entire_conditions();
		
		p = 0;
		h = 0;
		b = 0;
		m = 0;
		d = 0;

		for ( i=0; i<sizeof(cons); i++ )
		{
			coni = keys(cons)[i];
			conn = get_con_name(coni);
                        if (conn == "����")
				continue;
			if (values(cons)[i] < 0){
				tar->clear_condition(coni);
				continue;
			}
if (values(cons)[i] < 6)
                                cont = chinese_number(values(cons)[i]*10)+"��";
			else
                                cont = chinese_number(values(cons)[i] / 6)+"��";
			
			

			if ( !(conob = find_object(CON_DIR+coni+".c")) )
				conob = load_object(CON_DIR+coni+".c");
			
			if ( !conob )
			{
				//msg += sprintf("��%-48s��\n", "״̬�ļ��޷����أ�"+CON_DIR+coni+".c");
				continue;
			}

			switch (conob->query_type(me))
			{
				case "poison" : contp = HIB"��"NOR; p++; break;
				case "hurt"   : contp = HIR"��"NOR; h++; break;
				case "wound"  : contp = HIR"��"NOR; h++; break;
				case "busy"   : contp = HIY"æ"NOR; b++; break;
				case "job"    : contp = HIY"æ"NOR; b++; break;
				case "drug"   : contp = HIG"ҩ"NOR; d++; break;
				case "illness"   : contp = HIG"��"NOR; h++; break;
				default       : contp = WHT"��"NOR; m++; break;
			}
			

			msg += sprintf("��%-16s��%-24s��%|4s��%s\n", conn, cont, contp,wizardp(me)?(coni+".c"):"");
		}

		msg += "����������������������������������������������������\n";
		if (wizardp(me)) msg += sprintf("%51s\n", sprintf("����%d���ˣ�%d��æ��%d��ҩ��%d��������%d��������%d",
						 p, h, b, d, m, (p+b+h+d+m)));
		if ( (p+b+h+d+m) < 1 )
			tell_object(me, (tar!=me?tar->name(1):"��")+"����û�а����κ�����״̬��\n");
		else
			tell_object(me, msg);
		if (tar->is_robot())
			tell_object(me, HIY+(tar!=me?tar->name(1):"��")+"���ж�Ϊ�����ˣ��Ͽ���robot�����ٻ�һ�������ɡ�\n"+NOR);
		else
			tell_object(me,"��ǰ"+ (tar!=me?tar->name(1):"��")+"û�б��ж�Ϊ�����ˡ�\n");
	
	
	return 1;

}

int help(object me)
{
        write(@HELP
ָ���ʽ�� cond
           cond <��������>             (��ʦר��)

���ָ�������ʾ����ж���������������

HELP
        );
        return 1;
}
