

#include "ansi.h"
inherit NPC;
inherit F_MASTER;


void create()
{
        set_name("ŷ����", ({ "ouyang feng", "ouyang", "feng" }));
        set("long","���߹���һ�������������ף�������ꪣ�һ��������̡����ƣ�\n"+
                "������ֱ��Ѿõ��常ŷ���档\n" );
        set("nickname","����");
        set("title", "����ɽׯׯ��");
        set("gender", "����");
        set("age", 65);

        set_skill("cuff", 400);
        set_skill("strike", 360);
        set_skill("dodge", 360);
        set_skill("hamabu", 360);
        set_skill("parry", 360);
        set_skill("force", 360);
        set_skill("hamagong", 400);
        set_skill("staff", 400);
        set_skill("lingshe-zhangfa",400);
        set_skill("staff",400);
        set_skill("poison",400);
        map_skill("strike","hamagong");
        map_skill("dodge","hamabu");
        map_skill("parry", "hamagong");
        map_skill("force","hamagong");
        map_skill("staff","lingshe-zhangfa");
        prepare_skill("strike","hamagong");

        set("str", 33);
        set("int", 28);
        set("con", 29);
        set("dex", 28);

        set("max_qi", 5500);
        set("qi",5500);
        set("max_jing", 3000);
        set("jing",3000);
        set("neili", 6000);
        set("max_neili", 6000);
        set("jiali", 0);
        set("combat_exp", 3600000);

                  set("attitude", "peaceful");
                  set("shen_type", -1);

                  create_family("����ɽ", 1 , "ׯ��");
        set("inquiry", ([
                "ŷ����" : "ŷ���桢ŷ���棬������������ͦ��ġ�����\n",
         ]));

        setup();
        carry_object("/d/baituo/obj/gs-zhang")->wield();
        carry_object(ARMOR_D("cloth"))->wear();

}

