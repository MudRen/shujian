// fei.c ��ɽ�ɵ��������� �ѱ�
// Lklv 2001.10.18 Modified

#include <ansi.h>
inherit NPC;

void create()
{
        set_name("�ѱ�", ({ "fei bin", "fei", "bin" }));
        set("nickname", HIY"��������"NOR);
        set("long", "������ʮ���꣬�е���ģ������쳣���ϴ�������Ʋ���룬����ɽ
�������������ĵ���ʦ�ܷѱ�һ�״������������кպ�������\n");
        set("gender", "����");
        set("age", 49);
        set("per", 18);
        set("attitude", "heroism");
        set("shen_type", -1);
        set("str", 25);
        set("int", 23);
        set("con", 26);
        set("dex", 26);
        set("unique", 1);

        set("max_qi", 3000);
        set("max_jing", 2000);
        set("eff_jingli", 2000);
        set("jiali", 50);
        set("combat_exp", 1500000);
        set("shen", -14000);

	set_skill("literate", 100);
	set_skill("force", 165);
	set_skill("parry", 180);
	set_skill("sword", 190);
	set_skill("dodge", 160);
	set_skill("hand", 160);
	set_skill("zhongyuefeng", 160);
	set_skill("songyang-shou", 160);
	set_skill("hanbing-zhenqi", 160);
	set_skill("songshan-jian", 190);

	map_skill("force", "hanbing-zhenqi");
	map_skill("dodge", "zhongyuefeng");
	map_skill("hand", "songyang-shou");
	map_skill("parry", "songshan-jian");
	map_skill("sword", "songshan-jian");
	prepare_skill("hand", "songyang-shou");
	create_family("��ɽ��", 3, "����");
	set("chat_chance", 25);
	set("chat_msg", ({
		(: random_move :)
	}) );
	set("chat_chance_combat", 10);
	set("chat_msg_combat", ({
		(: perform_action, "hand.yinyang" :),
                (: exert_function, "jianqi" :),
        }));
	set("inquiry", ([
		"��ɽ��" : "������ɽ������������֮�ף�\n",
		"��������" : "������������������֮�������޴󣬿������֡��䵱���⡣\n",
		"������" : "���������ǵ������ˣ�������ɲ⡣\n",
	]) );
        setup();
        carry_object(ARMOR_D("changpao1"))->wear();
}
