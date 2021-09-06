// tang.c ��ɽ�ɵ��������� ��Ӣ��
// Lklv 2001.10.18 Modified

#include <ansi.h>
inherit NPC;

void create()
{
        set_name("��Ӣ��", ({ "tang yinge", "tang", "yinge" }));
        set("nickname", HIC"����̫��"NOR);
        set("long", "����һ�����������ߣ�������������ʦ�ܡ�\n");
        set("gender", "����");
        set("age", 45);
        set("per", 20);
        set("attitude", "heroism");
	set("class", "songshan");
        set("shen_type", -1);
        set("str", 26);
        set("int", 26);
        set("con", 26);
        set("dex", 27);
        set("unique", 1);

        set("max_qi", 3000);
        set("max_jing", 2000);
        set("eff_jingli", 2000);
        set("jiali", 50);
        set("combat_exp", 1500000);
        set("shen", -15000);

	set_skill("force", 150);
	set_skill("hanbing-zhenqi", 150);
	set_skill("dodge", 160);
	set_skill("zhongyuefeng", 160);
	set_skill("hand", 150);
	set_skill("songyang-shou", 150);
	set_skill("parry", 150);
	set_skill("sword", 150);
	set_skill("songshan-jian", 150);
	set_skill("literate", 100);

	map_skill("force", "hanbing-zhenqi");
	map_skill("dodge", "zhongyuefeng");
	map_skill("hand", "songyang-shou");
	map_skill("parry", "songshan-jian");
	map_skill("sword", "songshan-jian");

	prepare_skill("hand", "songyang-shou");
	create_family("��ɽ��", 3, "����");
	set("chat_chance_combat", 10);
	set("chat_msg_combat", ({
                (: perform_action, "sword.feiwu" :),
                (: perform_action, "hand.junji" :),
                (: perform_action, "strike.hanbing" :),
                (: exert_function, "jianqi" :),
        }));
	set("inquiry", ([
		"��ɽ��" : "������ɽ������������֮�ף�\n",
		"��������" : "������������������֮�������޴󣬿������֡��䵱���⡣\n",
		"������" : "���������ǵ������ˣ�������ɲ⡣\n",
	]) );
        setup();
        carry_object(ARMOR_D("changpao1"))->wear();
        carry_object(BINGQI_D("changjian"))->wield();
        add_money("gold", 1);
}

#include "app3.h";