// liang.c

inherit NPC;

#include <ansi.h>;
void create()
{
        set_name("������", ({ "liang ziweng", "liang", "ziweng" }));
        set("gender", "����");
        set("nickname", HIR"����"HIW"�Ϲ�"NOR);
        set("age", 43);
        set("str", 25);
        set("per", 20);
        set("dex", 16);
        set("long", "����������еȣ���ͷ�׷�����������ɫ����������ģ���һ
���𲼳��ۣ����ǵ����ס����ǳ���ɽ��ѧ��һ����ʦ��\n");
        set("combat_exp", 600000);
        set("shen_type", -1);
        set("attitude", "peaceful");

        set_skill("force", 160);
        set_skill("xuantian-wuji", 180);
        set_skill("dodge", 156);
        set_skill("taxue-wuhen", 170);
        set_skill("strike", 170);
        set_skill("parry", 180);
        set_skill("kunlun-zhang", 180);

        map_skill("force", "xuantian-wuji");
        map_skill("dodge", "taxue-wuhen");
        map_skill("strike", "kunlun-zhang");
        map_skill("parry", "kunlun-zhang");
        prepare_skill("strike", "kunlun-zhang");

        set("neili", 3800); 
        set("max_neili", 3800);
        set("qi", 2400);
        set("max_qi", 2400);
        set("eff_jingli",2200);
        set("jingli", 2200);
        set("jiali", 50);

        setup();
        carry_object(__DIR__"obj/changpao")->wear();
}

