// wu.c

inherit NPC;

#include <ansi.h>;
void create()
{
        set_name("������", ({ "wu qinglie", "wu", "qinglie" }));
        set("gender", "����");
        set("title", HIY"�ƺ��Ĺ��϶�"NOR);
        set("nickname", HIC"׷��ǹ"NOR);
        set("age", 32);
        set("str", 25);
        set("dex", 16);
        set("per", 21);
        set("long", "�������ǻƺ��Ĺ���϶����ǹ�������ɳͨ��Ķ����ӣ���
ʹ��ǹ��\n");
        set("combat_exp", 300000);
        set("shen_type", -1);
        set("attitude", "peaceful");

        set_skill("force", 120);
        set_skill("xuantian-wuji", 120);
        set_skill("spear", 120);
        set_skill("zhong-qiang", 120);
        set_skill("dodge", 90);
        set_skill("taxue-wuhen", 100);
        set_skill("strike", 90);
        set_skill("parry", 90);
        set_skill("kunlun-zhang", 80);
        set_skill("literate", 60);

        map_skill("spear", "zhong-qiang");
        map_skill("force", "xuantian-wuji");
        map_skill("dodge", "taxue-wuhen");
        map_skill("strike", "kunlun-zhang");
        map_skill("parry", "zhong-qiang");
        prepare_skill("strike", "kunlun-zhang");

        set("neili", 400); 
        set("max_neili", 400);
        set("jiali", 10);

        setup();
        carry_object("/clone/weapon/changqiang")->wield();
        carry_object("/clone/misc/cloth")->wear();
}


