// chuzi.c
// Modified by Numa 19991108

inherit NPC;
string ask_food();
string ask_water();

void create()
{
        set_name("��ʦ", ({ "chu zi", "chu" }));
        set("title", "�������");
        set("long", 
                "������̵�һ�����ӣ�Ц���еؿ����㣬�����ܺ��Ƶ����ӡ�\n");
        set("gender", "����");
        set("age", 34);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 26);
        set("int", 30);
        set("con", 26);
        set("dex", 28);
        
        set("max_qi", 200);
        set("max_jing", 50);
        set("neili", 0);
        set("max_neili", 0);
        set("jiali", 0);
        set("combat_exp", 500);
        set("shen",0);
        set("score", 0);

        set_skill("force", 10);
        set_skill("dodge", 10);
        set_skill("cuff", 10);
        set_skill("parry", 10);

        create_family("�������", 11, "����");
        set("inquiry", ([
              "��" : (: ask_water :),
              "ˮ" : (: ask_water :),
              "����" : (:ask_food:),
              "ʳ��" : (:ask_food:),
        ]));

        setup();
        
}

void init()
{       
        object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

string ask_food()
{                    
        object ob;
        object me;
                object food;
        ob=this_object();
        me=this_player();
        if ((me->query("food")*10/me->max_water_capacity())>8)
                return "����ô�Ա��˻���Ҫ��";
        if ( present("rice", this_player()))
                return "�ȳ������Ҹ������˵�ɡ�";
        if ( present("rice",  environment(me)) )
                return "�ǲ��������ȳ�������˵��";              
        food = new (FOOD_D("zongzi"));
        food->move(environment(ob));
        return "����������ȵ����Ӹ���ɣ��������Ӵ��";

}
 
string ask_water()
{
        object ob;
        object me;
        object water;
        ob = this_object();
        me = this_player();
        if ((me->query("water")*10/me->max_water_capacity())>8)
                return "����ô�ȱ��˻���Ҫ��";
        if ( present("tea", this_player()))
                return "�Ⱥ������Ҹ������˵�ɡ�";
        if ( present("tea",  environment(me)) )
                return "�ǲ��������Ⱥ�������˵��";
        water = new (FOOD_D("tang"));
        water->move(environment(ob));
        return "�Ɑ�����͸���ɣ��������Ӵ��";
        
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
         
        command(":) "+ob->query("id"));
        command("say ����������˰ɣ��Ҹ���Ū��Եĺͺȵġ�");
}
