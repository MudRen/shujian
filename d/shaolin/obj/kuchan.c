inherit NPC;
//string ask_me();
void create()
{
        set_name("����ʯ��", ({
                "kuchan shiren",
                "kuchan",
                "shiren",
	}));
	set("long",
                "�����Զ���޷�����������֮��ò��\n"
                "������ĸߴ����ݻƣ����һ�������¡�\n"
	);
        set("gender", "����");
	set("attitude", "friendly");
	set("class", "bonze");
        set("no_quest",1);
        set("age", 100);
	set("shen_type", 1);
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
        set("max_qi", 1200);
        set("max_jing", 1000);
        set("neili", 2000);
        set("max_neili", 2000);
        set("jiali", 50);
        set("combat_exp", 1200000);
        set("score", 200);
        set_skill("force", 140);
      set_skill("yijin-jing",140);
        set_skill("jingang-quan", 140);
        set_skill("dodge", 140);
        set_skill("shaolin-shenfa", 140);
        set_skill("cuff", 140);
        set_skill("parry", 140);
        set_skill("buddhism", 140);
        map_skill("force", "yijin-jing");
	map_skill("dodge", "shaolin-shenfa");
        map_skill("cuff", "jingang-quan");
        map_skill("parry", "jingang-quan");
        prepare_skill("cuff", "jingang-quan");

        setup();
}
#include "chan.h" 
