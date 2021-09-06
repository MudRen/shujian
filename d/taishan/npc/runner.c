// By Darken@SJ for tsjob

#include <ansi.h>
inherit NPC;

string *path = ({"southdown","southdown","southdown","southdown","southdown","southdown","southdown","westdown",
	"southdown","southdown","southdown","west","southwest","west","west","west","north","southwest","west",
	"north","west","northup","westup","northup","northup","northup","up","west","northwest","westup","northdown",
        "northup","northup","northup","northup","northwest","northwest","northeast","northup","north","north",
        "north","north","north","north","north","northup","north","northup","northup","northup"
});

void create()
{
        set_name("̩ɽ����ͽ", ({ "pantu"}) );
        set("gender", "����");
        set("age", 30);
        set("long",
                "����һ��̩ɽ�ɵ���ͽ���������ʣ�һ����ʱ׼����������ӡ�\n");

        set("combat_exp", 100000);

        set("str", 20);
        set("con", 20);
        set("int", 20);
        set("dex", 20);

        set("max_qi", 500);
        set("eff_qi", 500);
        set("qi", 500);
        set("max_jing", 500);
        set("jing", 500);
        set("neili", 500);
        set("max_neili", 500);
        set("jiali", 30);

        set_skill("sword", 100);
        set_skill("force", 100);
        set_skill("parry", 100);
        set_skill("dodge", 100);
        set_skill("cuff", 100);
        set_skill("yinyun-ziqi", 100);
        set_skill("taizu-quan", 100);
        set_skill("taishan-jianfa", 100);
        set_skill("qingmang-jianfa", 100);
        map_skill("force", "yinyun-ziqi");
        map_skill("sword", "taishan-jianfa");
        map_skill("parry", "taishan-jianfa");
        map_skill("dodge", "qingmang-jianfa");
        map_skill("cuff","taizu-quan");
        prepare_skill("cuff", "taizu-quan");

        create_family("̩ɽ��", 14, "��ͽ");

        set("no_follow",1);
        setup();

        carry_object("/clone/weapon/changjian")->wield();
}

void movement(int step)
{
        if (step == 0)
        	command("say ֻҪ���һ������������������������к����ӹ���");

        command("halt");
        command(path[step]);
        if (environment(this_object()) == this_object()->query("lastroom"))
                step -= 1;
        set("progress",step);
        if (step == 50)
                destruct(this_object());
        else if (step < 5 + random(3))
                movement(step+1);
        else
        {
                if (query("combat_exp") > 10000000)
                        call_out("movement", random(5)+2, step+1);
                else
                        call_out("movement", 10+random(3), step+1);
        }
}

void die()
{
        object killer;

        command("lovepoem pantu");
        killer = query_temp("last_damage_from");
        if (objectp(killer))
                if (killer->query_temp("tsjob/asked") && killer->query_temp("tsjob/target") == this_object())
                {
                        if (!query("progress"))
                        	set("progress",40);
                        killer->add_temp("tsjob/asked", 50-query("progress"));
                        killer->set_temp("tsjob/killed", 1);
                }
        ::die();
}


