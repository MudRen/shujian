inherit NPC;
//string ask_me();
void create()
{
        set_name("����ʯ��", ({
                "mingchan shiren",
                "mingchan",
                "shiren",
	}));
	set("long",
                "�����Զ���޷�����������֮��ò��\n"
                "����İ�С�������ƺ�һ�����ܽ�������\n"
	);
        set("gender", "����");
	set("attitude", "friendly");
	set("class", "bonze");
        set("no_quest",1);
        set("age", 100);
	set("shen_type", 1);
        set("str", 32);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
        set("max_qi", 1200);
        set("max_jing", 1000);
        set("neili", 1000);
        set("max_neili", 1000);
        set("jiali", 150);
        set("combat_exp", 1000000);
        set("score", 200);
        set_skill("force", 160);
        set_skill("hunyuan-yiqi",150);
        set_skill("youming-zhao", 160);
        set_skill("dodge", 150);
        set_skill("shaolin-shenfa", 150);
        set_skill("claw", 160);
        set_skill("parry", 160);
        set_skill("buddhism", 160);
    	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
        map_skill("claw", "youming-zhao");
        map_skill("parry", "youming-zhao");
        prepare_skill("claw", "youming-zhao");

        setup();
}
#include "chan.h"
