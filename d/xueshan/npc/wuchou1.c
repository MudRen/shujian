// wuchou-1.c ���
// by iceland

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("���", ({"da chou","dachou","chou","da"}));
	set("long",
"���ǲر�����е��ϴ󣬹��򲻸ߣ��������˲��١�\n"
"���Ǵ����´���͵ĵ��ӡ�\n"
	);

        set("title", HIY "�����µ�ʮ�Ĵ�����" NOR);
	set("gender", "����");
	set("attitude", "heroism");
	set("class", "huanxi");

	set("age", 26);
	set("shen_type", -1);
	set("str", 20);
	set("int", 15);
	set("con", 20);
	set("dex", 20);
	set("max_qi", 300);
	set("eff_jing", 200);
	set("max_jing",200);
	set("neili", 400);
	set("max_neili", 400);
	set("jiali", 10);
	set("combat_exp", 12000);
	set("score", 5000);
	set("unique", 1);

	set_skill("force", 25);
	set_skill("longxiang-boruo", 25);
	set_skill("dodge", 25);
	set_skill("yuxue-dunxing", 25);
	set_skill("blade", 25);
	set_skill("xuedao-jing", 25);
	set_skill("parry", 25);
	set_skill("huanxi-chan", 25);
	set_skill("literate", 20);

	map_skill("force", "longxiang-boruo");
	map_skill("dodge", "yuxue-dunxing");
	map_skill("blade", "xuedao-jing");
	map_skill("parry", "xuedao-jing");

	create_family("������", 14, "����");

        set("chat_chance", 2);
        set("chat_msg", ({
"�����Ц�˼����������������񫣡��������С�����ɡ���\n",
        }) );

	setup();

        carry_object(ARMOR_D("pijia"))->wear();
        carry_object(BINGQI_D("xinyuedao"))->wield();
        carry_object(MISC_D("chungongtu"));

        add_money("silver",20); 
}