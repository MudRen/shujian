// Npc : beijinyi.c ������
// Made by Jackie
// 12345...��ɽ���ϻ�....


#include "sujia.h"
inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("������", ({ "bei jinyi", "bei", "jinyi" }));
        set("long", 
                "���Ƕ������׼ҵ��ӱ����ǡ�\n"
                "������һ��������ĸ�����������˳��\n"
        );
        set("gender", "Ů��");
        set("age", 30);
        set("attitude", "friendly");
         set("unique", 1);
        set("shen_type", 1);
        set("str", 25);
        set("int", 25);
        set("con", 25);
        set("dex", 25);     
        set("max_qi", 1000);
        set("max_jing", 1000);
        set("neili", 1000);
        set("max_neili", 1000);
        set("jiali", 20);
        set("combat_exp", 400000);

	set_skill("dacheng-fofa", 80);
        set_skill("linji-zhuang", 80);
	set_skill("huifeng-jian", 85);
	set_skill("sword", 90);
	set_skill("literate", 90);
	set_skill("parry", 90);
	set_skill("dodge", 80);
	set_skill("force", 100);
	set_skill("anying-fuxiang", 90);

	map_skill("force", "linji-zhuang");
	map_skill("sword", "huifeng-jian");
	map_skill("parry", "huifeng-jian");
	map_skill("dodge", "anying-fuxiang");
        create_family("������", 4, "����");
        setup();
	carry_object("/d/emei/obj/changjian")->wield();
	carry_object("/d/emei/obj/shoes")->wear();
	carry_object("/d/emei/obj/cloth")->wear();

}

