// lu.c ��ɽ�ɵ��������� ½��
// Lklv 2001.10.18 Modified

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("½��", ({ "lu bo", "lu", "bo" }));
        set("nickname", HIM"�ɺ���"NOR);
        set("long", "����һ�����������ߣ���ɽ�����������ѽ��Ρ�\n");
        set("gender", "����");
        set("age", 46);
        set("per", 18);
        set("attitude", "heroism");
        set("shen_type", -1);
        set("str", 24);
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

	set_skill("force", 170);
	set_skill("hanbing-zhenqi", 150);
	set_skill("dodge", 170);
	set_skill("zhongyuefeng", 170);
	set_skill("hand", 160);
	set_skill("songyang-shou", 160);
	set_skill("parry", 170);
	set_skill("sword", 170);
	set_skill("songshan-jian", 170);
	set_skill("literate", 100);
	map_skill("force", "hanbing-zhenqi");
	map_skill("dodge", "zhongyuefeng");
	map_skill("hand", "songyang-shou");
	map_skill("parry", "songshan-jian");
	map_skill("sword", "songshan-jian");
	prepare_skill("hand", "songyang-shou");
	create_family("��ɽ��", 3, "����");
	set("chat_chance_combat", 20);
	set("chat_msg_combat", ({
                (: perform_action, "sword.feiwu" :),
                (: exert_function, "juhan" :),
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