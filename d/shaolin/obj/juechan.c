inherit NPC;
//string ask_me();
void create()
{
        set_name("����ʯ��", ({
                "juechan shiren",
                "juechan",
                "shiren",
	}));
	set("long",
                "�����Զ���޷�����������֮��ò��\n"
                "������еȣ�������Ƿ��������絶������һ�㡣\n"
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
        set_skill("yizhi-chan", 140);
        set_skill("dodge", 140);
        set_skill("shaolin-shenfa", 140);
        set_skill("finger", 140);
        set_skill("parry", 140);
        set_skill("buddhism", 140);
        map_skill("force", "yijin-jing");
	map_skill("dodge", "shaolin-shenfa");
        map_skill("finger", "yizhi-chan");
        map_skill("parry", "yizhi-chan");
        prepare_skill("finger", "yizhi-chan");

        setup();
}
#include "chan.h" 
