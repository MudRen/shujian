inherit NPC;
//string ask_me();
void create()
{
        set_name("����ʯ��", ({
                "jichan shiren",
                "jichan",
                "shiren",
	}));
	set("long",
                "�����Զ���޷�����������֮��ò��\n"
                "�������쳣��ʵ����������������һ�㡣\n"
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
        set("neili", 1000);
        set("max_neili", 1000);
        set("jiali", 100);
        set("combat_exp", 1200000);
        set("score", 200);
        set_skill("force", 140);
        set_skill("qianye-shou",140);
        set_skill("hunyuan-yiqi", 140);
        set_skill("dodge", 140);
        set_skill("shaolin-shenfa", 140);
        set_skill("hand", 140);
        set_skill("parry", 140);
        set_skill("buddhism", 140);
    	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
        map_skill("hand", "qianye-shou");
        map_skill("parry", "qianye-shou");
        prepare_skill("hand", "qianye-shou");

        setup();
}
#include "chan.h"
