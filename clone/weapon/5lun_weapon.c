//bestfalun.c �����
//by iceland
#include <ansi.h>
#include <weapon.h>
inherit HAMMER;
inherit F_UNIQUE;
void create()
{
        set_name( HIR"�����"NOR,({ "fenghuo lun" ,"lun" ,"falun","fenghuolun"}));
        set_weight(75000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "ֻ");
                set("long",HIR"��ֻ�Ӵ�ķ���������źܶ�����ͼ����ת��֮�������Գ�������ڣ����Ǵ�˵�еı���--����֡�\n"
                           "��������ֻ������϶��ɣ���������㹻��Ӧ�ÿ��Էֿ�(fenkai)��\n"NOR);
                set("value", 1500);
                set("rigidity", 10);
                set("sharpness", 8);
                set("weapon_prop/dodge", 2);
                set("weapon_prop/parry", 10);     
                set("wield_neili", 800);
                set("wield_maxneili", 1800);
                set("wield_str", 40);
                set("material", "gsbil");
                set("wield_msg", HIR"$N�ӱ���ȡ��һֻ$n"HIR"�������У�˲�����ذ�������������������ܶ���\n"NOR);
                set("unwield_msg",HIR"$N��ͷ����$n"HIR"�������̾�˿�������������ı����˱���\n"NOR);
	}
        init_hammer(150);
	setup();
}
void init()
{
    add_action("do_sub",({"fenkai", "�ֿ�"}));
}

int do_sub()
{
     object me,ob;
     object ob1, ob2, ob3, ob4, ob5;;
     me = this_player();
     if((int)me->query_skill("longxiang-boruo",1)<200)
     return notify_fail("����������������Ϊ��δͻ�Ƶ�ʮ�����˾������޷��ֿ����֡�\n");
     ob = this_object();
     ob1 = unew(BINGQI_D("gold-falun"));
     ob2 = unew(BINGQI_D("silver-falun"));
     ob3 = unew(BINGQI_D("bronze-falun"));
     ob4 = unew(BINGQI_D("iron-falun"));
     ob5 = unew(BINGQI_D("leaden-falun"));
     if (clonep(ob1) && clonep(ob2) && clonep(ob3) && clonep(ob4) && clonep(ob5)) {
             ob1->move(me);
             ob2->move(me);
             ob3->move(me);
             ob4->move(me);
             ob5->move(me);
             message_vision(HIY"$N�������һת��ֻ�������������죬�����ɢ������ֻ���֡�\n"NOR, me);
             destruct(ob);
		return 1;
     }
	if (ob1) destruct(ob1);
	if (ob2) destruct(ob2);
	if (ob3) destruct(ob3);
	if (ob4) destruct(ob4);
	if (ob5) destruct(ob5);
     return notify_fail("����ͼ������ֳַ�������֣�ȴ�������ֻ�����Ƕ��ʵ���޷��ֿ���\n");
}
