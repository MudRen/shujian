// NPC : /d/wudang/npc/taohua.c Ů��ͯ�һ�
// Cht update this NPC,xixixixi...........................

inherit NPC;

int ask_me1();
int ask_me();
void create()
{
        set_name("�һ�", ({"tao hua"}) );
        set("nickname", "ɽ��һ֦��");
        set("gender", "Ů��" );
        set("age", 12+random(6));
        set("long",
          "���Ǹ���ޢ������С�����˵���䵱ɽ��һ��ͯ�������á�\n"
          "�ֽ��ڿ죬����ϲ������������΢ʾ�⣬���ȥ�Ӳ赹ˮ��\n");
       set("attitude", "friendly");
       set("shen_type", 1);

        set("str", 20);
        set("int", 28);
        set("con", 24);
        set("dex", 20);

        set("max_qi", 150);
        set("max_jing", 100);
        set("neili", 150);
        set("max_neili", 150);

        set("combat_exp", 1000+random(800));
        set("score", 1000);

        set_skill("force", 30);
        set_skill("dodge", 20);
        set_skill("unarmed", 15+random(10));
        set_skill("parry", 20);
        set_temp("apply/attack", 10);
        set_temp("apply/defense", 15);
        set_temp("apply/damage", 3);

         set("inquiry", ([
           "��ҩ����" : (: ask_me :),
           "rumor" : (: ask_me1 :),
             ]) );
        setup();
//                carry_object("/u/lius/wudang/obj/cloth")->wear();
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

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;

        say("�һ�Ц������˵������λ" + RANK_D->query_respect(ob)
             + "����������" + "����͸����ϲ衣\n");
}


void serve_tea(object who)
{
        object obn;
        object room;

        if( !who || environment(who) != environment() ) return;

        if( !who->query_temp("marks/sit") ) return;
        
        if( !objectp(room = environment()) ) return;

        if ( (int)who->query_temp("tea_cup") <= 0 )
        {
                obn = new("/d/wudang/obj/dawancha");
                obn->move(room);
                message_vision("�һ�������������������ϵĴ���赹����\n",
                        who);
        } else 
        {
                who->add_temp("tea_cup", -1);
                obn = new("/d/wudang/obj/xiangcha");
                obn->move(room);
                message_vision("�һ��ó�������С��������˱���裬�������ϣ�\n",
                        who);
        }

        obn = new("/d/wudang/obj/mitao");
        obn->move(room);
        message_vision("�һ��ó�һ�����ʵ�ˮ���ң��������ϣ�\n", who);
        
        return;
}

int ask_me()
{
        object me, ob;

        ob = this_player();
        me = this_object();
       
        command("nod " + ob->query("id"));
    	command("say ż��������������Ϊ����ͣ��Ǹ��ܺõ��ˡ�\n");
	return 1;
}
int ask_me1()
{
        object me, ob;

        ob = this_player();
        me = this_object();
        if(!ob->query_temp("marks/ask2")){
         command("say " + RANK_D->query_respect(ob) + "��֪���Ƿ�������飿\n");
         return 1;
         }
        command("say ��˵��һλ���������ں�ɽ�����Ǻ��ٿ�������Ҳ��֪�������Ǽ١�\n");
        ob->set_temp("marks/taohua",1);
	return 1;
}       
