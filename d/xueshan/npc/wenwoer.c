// wenwoer.c ���Զ�
// by iceland

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("���Զ�", ({"wenwo er","wenwoer","wenwo","er"}));
	set("long",
                "�����ð������֣�������Բ������Ũü��һ˫ţ�ۣ�����΢΢��\n"
                "�����ţ�������������ӡ�\n"
	);

        set("title", HIY "�����µ�ʮ��������" NOR);
	set("gender", "����");
	set("attitude", "friendly");
	set("class", "huanxi");

	set("age", 30);
	set("shen_type", -1);
	set("str", 26);
	set("int", 15);
	set("con", 25);
	set("dex", 22);
	set("max_qi", 550);
	set("eff_jing", 200);
	set("max_jing",200);
	set("neili", 550);
	set("max_neili", 550);
	set("jiali", 20);
	set("combat_exp", 70000);
	set("score", 5000);
	set("unique", 1);

	set_skill("force", 35);
	set_skill("longxiang-boruo", 35);
	set_skill("dodge", 35);
	set_skill("yuxue-dunxing", 35);
	set_skill("hand", 35);
	set_skill("dashou-yin", 35);
	set_skill("parry", 35);
	set_skill("huanxi-chan", 35);
	set_skill("literate", 30);

	map_skill("force", "longxiang-boruo");
	map_skill("dodge", "yuxue-dunxing");
	map_skill("hand", "dashou-yin");
	map_skill("parry", "dashou-yin");

	prepare_skill("hand", "dashou-yin");

	create_family("������", 13, "����");

	setup();

        carry_object(__DIR__"obj/qinxiu-jiasha")->wear();
}