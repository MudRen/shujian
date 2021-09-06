// wan.c ��ɽ�ɵ��Ĵ����� ���ƽ
// Lklv 2001.10.18 Modified

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("���ƽ", ({ "wan daping", "wan", "daping" }));
        set("nickname", "ǧ����");
        set("long", "������������ͽ�ܣ�����λ������ߵĻ������ӡ�\n");
        set("gender", "����");
        set("age", 29);
        set("per", 20);
        set("attitude", "heroism");
        set("class", "songshan");
        set("shen_type", -1);
        set("str", 26);
        set("int", 20);
        set("con", 23);
        set("dex", 23);
        set("unique", 1);

        set("max_qi", 1500);
        set("max_jing", 1000);
        set("eff_jingli", 1000);
        set("jiali", 20);
        set("combat_exp", 650000);
        set("shen", -6500);

	set_skill("force", 110);
	set_skill("hanbing-zhenqi", 105);
	set_skill("dodge", 90);
	set_skill("zhongyuefeng", 90);
	set_skill("hand", 90);
	set_skill("songyang-shou", 90);
	set_skill("parry", 90);
	set_skill("sword", 100);
	set_skill("songshan-jian", 100);
	set_skill("literate", 50);
	map_skill("force", "hanbing-zhenqi");
	map_skill("dodge", "zhongyuefeng");
	map_skill("hand", "songyang-shou");
	map_skill("parry", "songshan-jian");
	map_skill("sword", "songshan-jian");
	prepare_skill("hand", "songyang-shou");
	set("chat_chance_combat", 10);
	set("chat_msg_combat", ({
		(: perform_action, "sword.feiwu" :),
		(: perform_action, "hand.junji" :),
                (: exert_function, "juhan" :),
	}));
	create_family("��ɽ��", 4, "����");
	setup();
	set("inquiry", ([
		"��ɽ��" : "������ɽ������������֮�ף�\n",
		"��������" : "������������������֮�������޴󣬿������֡��䵱���⡣\n",
		"������" : "���������ǵ������ˣ�������ɲ⡣\n",
	]) );
	carry_object(ARMOR_D("changpao1"))->wear();
	carry_object(BINGQI_D("changjian"))->wield();
}

#include "app4.h";