// seleng.c ɫ��
// by iceland

#include <ansi.h>

inherit NPC;

void create()
{
        set_name("ɫ��", ({ "se leng", "seleng" ,"se","leng" }));
        set("long",@LONG
��������İ�С���ʷ����֡���Ϊ�����¹�����������������С�ƽʱ���ܸ����£�
��������������������д�С�������
LONG
        );
        set("title", HIY "�����µ���" NOR);
        set("gender", "����");
        set("age", 35);
        set("attitude", "friendly");
        set("shen_type", -1);
        set("str", 20);
        set("int", 15);
        set("con", 20);
        set("dex", 20);
        set("max_qi", 300);
        set("eff_jing", 150);
	set("max_jing",150);
        set("neili", 100);
        set("max_neili", 100);
        set("combat_exp", 5000);
        set("score", 100);
	set("unique", 1);

        set_skill("huanxi-chan", 20);
        set_skill("force", 20);
        set_skill("longxiang-boruo", 20);
        set_skill("dodge", 20);
        set_skill("yuxue-dunxing", 20);
        set_skill("claw", 20);
        set_skill("tianwang-zhua", 20);
        set_skill("parry", 20 );

        map_skill("force", "longxiang-boruo");
        map_skill("dodge", "yuxue-dunxing");
        map_skill("parry", "tianwang-zhua");
        map_skill("claw", "tianwang-zhua");

        prepare_skill("claw","tianwang-zhua");

        create_family("������", 13, "����");
        set("class", "huanxi");

        set("chat_chance", 3);
	set("chat_msg", ({
"ɫ���������ֵ�����Ѳ�ӣ���ʱ�µ�������ɣ���ɣ���͵������\n",
"ɫ���������죺��ǰ����չ����治����\n",
"��ιι���㣡��ɫ�����ȥ�����Ÿ���ʵ�ͽ��Ĺ��������㵸����ĭ��ɵĴ�Ƣ����\n",
}) );
        setup();
        carry_object(__DIR__"obj/qinxiu-jiasha")->wear();

        add_money("silver",50);
}
