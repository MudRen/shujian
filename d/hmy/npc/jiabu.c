// jiabu.c
#include <ansi.h>
#include <wanted.h>
inherit NPC;

string give_pass();

string *unknow = ({
	"���Ǻ��ˣ�����ϵú�ľ�£�",
	"�пڣ���Ȼ��ܶ�����Ȩ��֪��",
	"��֪��",
});

void create()
{
        set_name("�ֲ�", ({ "jia bu", "jia", "bu"}));
	set("nickname", "��������");
        set("long",
"����һ��������Ҳ�ƻƣ�����̫��Ѩ�߸߹��𣬱������һ�Ⱥ������ơ�\n");
        set("title",HIY"�������  "HIC"�����ó���"NOR);
        set("gender", "����");
	set("age", 40);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("str", 23);
	set("int", 23);
	set("con", 24);
	set("dex", 28);

        set("max_qi", 2500);
        set("max_jing", 1500);
        set("eff_jingli", 1500);
        set("jiali", 50);
        set("combat_exp", 1200000);

        set_skill("parry",170);
        set_skill("dodge",170);
        set_skill("force",170);
        set_skill("strike",170);
        set_skill("literate", 120);
        set_skill("ding-dodge",170);
        set_skill("tianmo-gong",170);
        set_skill("tiangang-zhang",170);

        map_skill("dodge", "ding-dodge");
        map_skill("force", "tianmo-gong");
        map_skill("parry", "tiangang-zhang");
        map_skill("strike", "tiangang-zhang");
        prepare_skill("strike", "tiangang-zhang");

	set("inquiry", ([
		"�п�" : (: give_pass :)
	]));
        setup();

	carry_object(MISC_D("cloth"))->wear();
}

string give_pass()
{
	object me = this_object();
	object ob;

	ob = environment(me);
	if (ob == load_object("/d/hmy/shimen.c"))
	if (!is_wanted(this_player()) && random(3) == 1)
			return "���յ��п��ǣ�"+ob->query("pass");
	return unknow[random(sizeof(unknow))];
}
