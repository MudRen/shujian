//Write by Yanyang@SJ  2001.2.20
//TZ_chuzi.c
inherit NPC;
#include <ansi.h>
string ask_food();

void create()
{
       set_name("����", ({ "chu zi", "chuzi", }) );
       set("gender", "����" );
       set("age", 46);
       set("long", "�������ư��нƸ���ĳ��ӣ����÷�ͷ������װ����֡�\n");
       set("combat_exp", 2500);
       set("attitude", "friendly");

       set("inquiry", ([
             "ʳ��" : (: ask_food :),
             "food" : (: ask_food :),
       ]) );

       setup();
       carry_object(ARMOR_D("cloth"))->wear(); 
}

string ask_food()
{                    
        object me,food;
        mapping fam;
        me=this_player();

        if (mapp(fam = me->query("family")) && fam["family_name"] != "���ư�" ) return "��λ" + RANK_D->query_respect(me) + "���Ӷ����𣿿�ϧ���ư�Ļ�ʳ��ʱ�������д���ͣ�";

        if ((me->query("food")*10/me->max_water_capacity())>8)
                return "��λ" + RANK_D->query_respect(me) + "�����ű����ˣ���ô��Ҫ��";
        if ( present("mi fan", this_player()))
                return "��λ" + RANK_D->query_respect(me) + "���ϲ��ǻ�����ȳ�����˵�ɣ�";
        if ( present("ruzhu", this_player()))
                return "��λ" + RANK_D->query_respect(me) + "���ϲ��ǻ�����ȳ�����˵�ɣ�";
        if ( present("hongshao niurou", this_player()))
                return "��λ" + RANK_D->query_respect(me) + "���ϲ��ǻ�����ȳ�����˵�ɣ�";
        if ( present("mi fan",  environment(me)) )
                return "�ǲ��������ȳ�����˵�����˷��ˣ�";              
        if ( present("ruzhu",  environment(me)) )
                return "�ǲ��������ȳ�����˵�����˷��ˣ�";              
        if ( present("hongshao niurou",  environment(me)) )
                return "�ǲ��������ȳ�����˵�����˷��ˣ�";              
        food = new ("/d/tiezhang/obj/fan");
        food->move(environment()); 
        food = new ("/d/tiezhang/obj/ruzhu");
        food->move(environment());
        food = new ("/d/tiezhang/obj/hsnr");
        food->move(environment());
        say("���ӽ����˶˳��������������ϡ�\n");
        return "�������Ƕ����˰ɣ�����������Ե㣡";
}


