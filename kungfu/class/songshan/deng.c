// deng.c ��ɽ�ɵ��������� �˰˹�
// Lklv 2001.10.18 Modified

#include <ansi.h>
inherit NPC;

void create()
{
        set_name("�˰˹�", ({ "deng bagong", "deng", "bagong" }));
        set("nickname", HIC"���"NOR);
        set("long", "����һ�����������ߣ�һ����������ĳ����뻯��\n");
        set("gender", "����");
        set("unique", 1);
        set("age", 45);
        set("per", 20);
        set("attitude", "heroism");
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
        set("combat_exp", 2000000);
        set("eff_neili", 4000);
        set("shen", -15000);

	set_skill("literate", 100);
	set_skill("force", 155);
	set_skill("parry", 160);
	set_skill("whip", 180);
	set_skill("sword", 150);
	set_skill("dodge", 150);
	set_skill("hand", 140);
	set_skill("zhongyuefeng", 140);
	set_skill("songyang-shou", 140);
	set_skill("songyang-bian", 180);
	set_skill("hanbing-zhenqi", 150);
	set_skill("songshan-jian", 150);

	map_skill("force", "hanbing-zhenqi");
	map_skill("dodge", "zhongyuefeng");
	map_skill("hand", "songyang-shou");
	map_skill("whip", "songyang-bian");
	map_skill("parry", "songshan-jian");
	map_skill("sword", "songshan-jian");
	prepare_skill("hand", "songyang-shou");

	create_family("��ɽ��", 3, "����");

	set("class", "songshan");
	set("chat_chance_combat", 10);
	set("chat_msg_combat", ({
		(: perform_action, "hand.junji" :),
                (: exert_function, "juhan" :),
	}));
	set("inquiry", ([
		"��ɽ��" : "������ɽ������������֮�ף�\n",
		"��������" : "������������������֮�������޴󣬿������֡��䵱���⡣\n",
		"������" : "���������ǵ������ˣ�������ɲ⡣\n",
	]) );
        setup();
        carry_object(ARMOR_D("changpao1"))->wear();
        carry_object(BINGQI_D("whip"))->wield();
}

#include "app3.h";
