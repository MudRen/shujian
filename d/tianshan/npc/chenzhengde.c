// Npc: /d/tianshan/npc/chenzhende.c
// By Linux

#include <ansi.h>

inherit NPC;

void create()
{
        set_name("������", ({ "chen zhengde", "chen", "zhengde"}));
		set("long",
                "�����ǻؽ�һ������ǰ��ͺ�ճ����¡�\n"
                "������ѩ�����÷�ͳ���ɽ˫ӥ��\n"
                "������ĸߴ�ͺͷ��������⣬��ü�԰ס�\n");
        set("title",HIY"��ɽ˫ӥ"NOR);
        set("nickname", WHT"ͺ��"NOR);
        set("gender", "����");

        set("age", 66);
        set("attitude", "peaceful");
        set("shen_type", -1);
	set("per", 10);
        set("str", 27);
        set("int", 27);
        set("con", 27);
        set("dex", 30);

        set("max_qi", 3000);
        set("max_jing", 2200);
        set("eff_jingli", 2200);
        set("max_neili", 4000);
        set("jiali", 50);
        set("combat_exp", 1700000);

        set_skill("force", 250);
        set_skill("unarmed", 250);
        set_skill("dodge", 250);
        set_skill("parry", 250);
        set_skill("hand",250);
        set_skill("strike", 250);
        set_skill("sword",250);

        set_skill("zhemei-shou",250);          //��ң��÷��(hand)
        set_skill("liuyang-zhang",250);        //��ɽ������(strike)(unarmed)
        set_skill("yueying-wubu",250);       //ƾ���ٷ�(dodge)
        set_skill("bahuang-gong", 250);        //�˻�����Ψ�Ҷ���(force)
	set_skill("tianyu-qijian", 260);     //��ɽ����(sword)


        map_skill("force", "bahuang-gong");
        map_skill("strike","liuyang-zhang");
        map_skill("dodge", "yueying-wubu");
        map_skill("unarmed", "liuyang-zhang");
        map_skill("hand", "zhemei-shou");
        map_skill("parry", "tianyu-qijian");
	map_skill("sword", "tianyu-qijian");
        prepare_skill("hand","zhemei-shou");
        prepare_skill("strike","liuyang-zhang");

        setup();
        carry_object(BINGQI_D("changjian"))->wield();
        carry_object(MISC_D("cloth"))->wear();
        carry_object(ARMOR_D("shoes"))->wear();
}
