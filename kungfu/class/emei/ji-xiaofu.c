// /kungfu/class/emei/ji-xiaofu.c
// Make by jackie 98.2

#include "sujia.h"
inherit F_MASTER;
inherit NPC;

void create()
{
        set_name("����ܽ", ({
                "ji xiaofu",
                "ji",
                }));
        set("long",
                "����һλ��ò��Ů�ӣ�ʹ��һ���ϺõĻط��������\n"
        );


        set("gender", "Ů��");
        set("attitude", "friendly");
         set("unique", 1);

        set("age", 25);
        set("shen_type", 1);
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
        set("max_qi", 800);
        set("max_jing", 800);
        set("neili", 800);
        set("max_neili", 800);
        set("jiali", 8);
        set("combat_exp", 80000);
        set("score", 100);


        create_family("������", 4, "����");

        setup();

}

