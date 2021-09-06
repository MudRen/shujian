// color.c
// Modified by snowman@SJ 1999

#include <ansi.h>
inherit F_CLEAN_UP;

int help(object me);
int main(object me, string arg)
{
	string color;
	object ob = me;

	if (!wizardp(me) && me->query("combat_exp") < 500000)
		return notify_fail("��ľ��黹�������Լ���������ɫ�����Ͱ���\n");
	if (!wizardp(me) && me->query("color") &&
	me->query("color_time") >= me->query("combat_exp",1)/500000)
		return notify_fail("�㲻�Ǽӹ���ɫ����\n");
	if (!arg) return help(me);
	if (wizardp(me) && sscanf(arg, "%s %s", color, arg) == 2)
		ob = present(color, environment(me));
	if (!ob) return notify_fail("����û������ˡ�\n");

	switch (arg) {
		case "RED" : color = RED; break;
		case "GRN" : color = GRN; break;
		case "YEL" : color = YEL; break;
		case "BLU" : color = BLU; break;
		case "MAG" : color = MAG; break;
		case "CYN" : color = CYN; break;
		case "WHT" : color = WHT; break;
		case "HIR" : color = HIR; break;
		case "HIG" : color = HIG; break;
		case "HIY" : color = HIY; break;
		case "HIB" : color = HIB; break;
		case "HIM" : color = HIM; break;
		case "HIC" : color = HIC; break;
		case "HIW" : color = HIW; break;
		default :
			return notify_fail("��Ҫ�����ּ�ʲô��ɫ��\n");
	}
	ob->set("color", color);
        ob->add("color_time", 1);
	write("�Ӻ��ˡ�\n");
	write("���Ѿ�ʹ�������ָ��"+chinese_number(ob->add("color_time", 1))+"�Ρ�\n");
	return 1;
}

int help(object me)
{
	write("
ָ���ʽ : color <��ɫ>
 
���������ʮ���飬��ô����Ը����Լ����������ּ���һ����ɫ��
�Ժ�ÿ�õ���ʮ���飬����Ϊ�Լ������ֻ�һ����ɫ��
����Ŀǰ�ľ�����1,500,000����ô�Ϳ���ʹ�� color ָ�����Ρ�
��ѡ��������ɫ��

RED - "RED"��"NOR"��ɫ    HIR - "HIR"��"NOR"����ɫ
GRN - "GRN"��"NOR"��ɫ    HIG - "HIG"��"NOR"����ɫ
YEL - "YEL"��"NOR"����ɫ  HIY - "HIY"��"NOR"����ɫ
BLU - "BLU"��"NOR"����ɫ  HIB - "HIB"��"NOR"����ɫ
MAG - "MAG"��"NOR"ǳ��ɫ  HIM - "HIM"��"NOR"�ۺ�ɫ
CYN - "CYN"��"NOR"����ɫ  HIC - "HIC"��"NOR"����ɫ
WHT - "WHT"��"NOR"ǳ��ɫ  HIW - "HIW"��"NOR"����ɫ
\n");
	return 1;
}
