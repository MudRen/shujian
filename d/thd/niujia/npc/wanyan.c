// wanyanhonglie.c

inherit NPC;
#include <ansi.h>

void create()
{
        set_name("���պ���", ({"wanyan honglie", "honglie", "wanyan"}));
        set("gender", "����");
        set("title", HIY"��������ү"NOR);
        set("age", 31);
        set("class", "officer");
	      set("long","[1;31m�����������˺��ص��ˣ�����ȥ��Ҫ�����ˡ�[0m\n");
        set("attitude", "friendly");
        set("shen_type", -1);
        set("str", 26);
        set("per", 25);
        set("int", 25);
        set("con", 25);
        set("dex", 26);

        set("qi", 300);
        set("max_qi", 1000);
        set("jing", 200);
        set("max_jing", 200);
        set("neili", 300);
        set("max_neili", 300);
        set("jiali", 10);

        set("combat_exp", 30000);
        set("score", 10000);

        set_skill("force", 40);
        set_skill("dodge", 40);
        set_skill("parry", 40);
        set_skill("unarmed",40);

        setup();
        carry_object("/clone/armor/jinduan")->wear();
        carry_object("d/mr/obj/guanxue")->wear();

}

