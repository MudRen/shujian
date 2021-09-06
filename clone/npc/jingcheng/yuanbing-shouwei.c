inherit NPC;
#include <ansi.h>
#include <job_skill.h>
void create()
{
        set_name("Ԫ������", ({ "yuanbing shouwei", "shouwei"}));
        set("gender", "����");
        set("age", 20 + random(60));
        set("long", "����һ���������±�����Ԫ��������\n");
        if (random(20) < 5)
                set("double_attack",1);
        set("attitude", "peaceful");
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
        set("max_qi", 150000);
        set("qi", 150000);
        set("max_jing", 8000);
        set("jing", 8000);
        set("max_neili", 150000);
        set("neili", 150000);
        set("combat_exp", 10000000);
        set("no_get",1);
        set_basic();
        setup();
}
void init()
{
	      object me;
        object ob;
        me = this_player();
        ob=this_object();
        ::init();

        if (!me->query_temp("was_job/asked"))
                return;

        command("say �����ˣ����˽�����\n");
        if (!this_object()->query_temp("do_clone"))
                ob->do_clone(me, environment()->query_floor());
        if (!random(3))
                ob->do_clone(me, environment()->query_floor());
        kill_ob(me);
        me->kill_ob(this_object());
}

void die()
{
        switch (random(15))
        {
                case 0:
                        new(MEDICINE_D("jingcheng/shen-wan"))->move(this_object());
                        break;
                case 5:
                        new(MEDICINE_D("jingcheng/jinchuang-yao"))->move(this_object());
                        break;
                case 10:
                        new(MEDICINE_D("jingcheng/xiaohuan-dan"))->move(this_object());
                        break;
                case 15:
                        new(MEDICINE_D("jingcheng/jiedu-wan"))->move(this_object());
                        break;

        }
        ::die();
}
