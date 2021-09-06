//wang1.c
inherit NPC;
#include <ansi.h>
string ask_food();
string ask_water();

void create()
{
        set_name("С����", ({ "xiao chuzi", "chuzi" }) );
        set("gender", "����" );
        set("age", 28);
        set("long", 
             "С�����������ɵ�ʳ�ù��µġ����Բ������书��"
             "ֻ�������������ɰ��������Ĳˣ���������Ϊͽ��\n");
        set("str", 25);
        set("dex", 30);
        set("con", 17);
        set("int", 15);
        set("per", 20);
        set("shen", -300);
        set_skill("unarmed", 60);
        set_skill("force", 50);
        set_skill("dodge", 50);
        set_skill("zhaixingshu", 60);
        map_skill("dodge","zhaixingshu");
        set("combat_exp", 15000);

        set("max_qi", 500);
        set("max_jing", 500);

        create_family("������", 2, "����");

        set("attitude", "peaceful");
       set("inquiry", ([
             "name" : "С�����������ɵĳ��ӡ�",
             "����" : "�����˵����տ�������һ���������������˼�Ҳ���������Ĳˣ�",
             "ʳ��" : (: ask_food :),
             "ˮ" : (: ask_water :), 
       ]) );

        setup();
        carry_object(ARMOR_D("pink_cloth"))->wear();
        add_money("silver", 10);
}

string ask_food()
{                    
        object ob,me,food;
        ob=this_object();
        me=this_player();
        say("С����˵����������㷹��Ҳ�����ף����˷��ˡ���\n");
        if ((me->query("food")*10/me->max_water_capacity())>8)
                return "����ô�Ա��˻���Ҫ��";
        if ( present("cai yao", this_player()))
                return "�ȳ������Ҹ������˵�ɡ�";
        if ( present("cai yao",  environment(me)) )
                return "�ǲ��������ȳ�������˵��";              
        food = new (FOOD_D("caiyao"));
        food->move(me);
        return "���̲˾͸����ˣ������Ӵ��";
}
 
string ask_water()
{
        object ob,me,water;
        ob=this_object();
        me=this_player();
        if ((me->query("water")*10/me->max_water_capacity())>8)
                return "����ô�ȱ��˻���Ҫ��";
        if ( present("qing hulu", this_player()))
                return "�Ⱥ������Ҹ������˵�ɡ�";
        if ( present("qing hulu",  environment(me)) )
                return "�ǲ��������Ⱥ�������˵��";
        water = new(FOOD_D("hulu"));
        water->move(me);
        return "������«�͸���ɣ��������Ӵ��";        
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
         
        if ( ob->query("combat_exp") < 3000){
          command(":) "+ob->query("id"));
          command("say �����ǳ�����������ȿ�����ʲô�Եĺͺȵģ����û���������\n"+
          "Ҫʳ�� "HIY HBCYN"ask chuzi about ʳ��"CYN" ��\n�ȵ� "HIY HBCYN"ask chuzi about ˮ"CYN" �ɡ�"NOR);
        }
}
