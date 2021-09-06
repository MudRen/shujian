#include <ansi.h>
#include <dbase.h>

inherit NPC;
inherit F_VENDOR;
int ask_me();
int ask_songhua();
int do_song(string arg);
void create()
{
                  set_name("����", ({ "zi zhu", "zi" ,"zhu" }));
                  
                  set("shen_type", 1);
                  set("title",HIM"�����ϰ�"NOR);
                  set("no_get", 1);
        	  set("no_bark", 1);
        	  set("job_npc", 1);
        	  set("no_ansuan", 1);


                  set("gender", "Ů��");
                  set("per", 30);
                  set("age", 15);
                  set("long",
"�������������Ů��ֻ���京Ц�紺�ң��񴽺���,����ϸ��,��ȶ��ˣ�
��ֲ����£������������㣬ʵ���˼��ɫ��\n"
);
                  set("attitude", "friendly");
                  set("inquiry", ([
                                "�ͻ�" : (: ask_songhua :),
				"songhua" : (:ask_songhua :),
                  ]));


	set("vendor_goods", ({
           (["name":__DIR__"obj/flower/red_rose","number":99]),
           (["name":__DIR__"obj/flower/white_rose","number":99]),
           (["name":__DIR__"obj/flower/pink_rose","number":99]),
           (["name":__DIR__"obj/flower/blue_rose","number":99]),
           (["name":__DIR__"obj/flower/yellow_rose","number":99]),
	   (["name":__DIR__"obj/flower/qingren_cao","number":99]),
           (["name":__DIR__"obj/flower/ding_xiang","number":99]),
	   (["name":__DIR__"obj/flower/mu_dan","number":99]),
           (["name":__DIR__"obj/flower/yu_jinxiang","number":99]),
	   (["name":__DIR__"obj/flower/bai_he","number":99]),
           (["name":__DIR__"obj/flower/kang_naixin","number":99]),
	   (["name":__DIR__"obj/flower/ma_tilian","number":99]),
           (["name":__DIR__"obj/flower/jin_yucao","number":99]),
           (["name":__DIR__"obj/flower/huo_he","number":99]),
           (["name":__DIR__"obj/flower/hu_dielan","number":99]),
	   (["name":__DIR__"obj/flower/qiu_haitang","number":99]),
           (["name":__DIR__"obj/flower/shi_hulan","number":99]),
           (["name":__DIR__"obj/flower/mms","number":99])
        }));


                  setup();
	          carry_object("d/city/obj/pink_cloth")->wear();
		  carry_object("d/city/obj/flower_shoe")->wear();


                  remove_call_out("do_check_flower");
                  call_out("do_check_flower", 10+random(10) );

		  remove_call_out("do_full_flower");
                  call_out("do_full_flower", 1800 );
}

int do_full_flower()
{
   
	 tell_room(environment(), "\n�������������ʻ����˽�����\n");
	 tell_room(environment(), "���ˣ��������Ǹ������ʻ����ˡ�����ͷ���Ǹ�������������к���\n");
	 tell_room(environment(), "������ϲ��������лл�������壬���ں���Ļ�����ɡ���\n");
 	 tell_room(environment(), "�������߹�ȥ�������úá�\n");
	 tell_room(environment(), "���������˳���������˵���������ź��ˣ������´���������\n");
	 tell_room(environment(), "���������˳�ȥ��\n");

	set("vendor_goods", ({
           (["name":__DIR__"obj/flower/red_rose","number":99]),
           (["name":__DIR__"obj/flower/white_rose","number":99]),
           (["name":__DIR__"obj/flower/pink_rose","number":99]),
           (["name":__DIR__"obj/flower/blue_rose","number":99]),
           (["name":__DIR__"obj/flower/yellow_rose","number":99]),
	   (["name":__DIR__"obj/flower/qingren_cao","number":99]),
           (["name":__DIR__"obj/flower/ding_xiang","number":99]),
	   (["name":__DIR__"obj/flower/mu_dan","number":99]),
           (["name":__DIR__"obj/flower/yu_jinxiang","number":99]),
	   (["name":__DIR__"obj/flower/bai_he","number":99]),
           (["name":__DIR__"obj/flower/kang_naixin","number":99]),
	   (["name":__DIR__"obj/flower/ma_tilian","number":99]),
           (["name":__DIR__"obj/flower/jin_yucao","number":99]),
           (["name":__DIR__"obj/flower/huo_he","number":99]),
           (["name":__DIR__"obj/flower/hu_dielan","number":99]),
	   (["name":__DIR__"obj/flower/qiu_haitang","number":99]),
           (["name":__DIR__"obj/flower/shi_hulan","number":99]),
           (["name":__DIR__"obj/flower/mms","number":99])
        }));
	 remove_call_out("do_full_flower");
         call_out("do_full_flower",1800);
	 return 1;
	
}

private void go_home()
{
	if( !living(this_object()) ) return;
        message_vision("$N��ɫ���ŵ��뿪�ˡ�\n", this_object());
        this_object()->move("/d/city/huadian");
	message_vision("$N�첽���˹�����\n", this_object());
}
	



void init()
{
     if( environment() != load_object("/d/city/huadian") ) 
		{
		remove_call_out("go_home");
		call_out("go_home", 1);
	}
    	 add_action("do_list", "list");
         add_action("do_buy", "buy");
         add_action("do_song", "song");
         //add_action("do_check_flower", "check_test");

}


string query_flower_file( string arg)
{
         return sprintf( DATA_DIR "flower/%c/%s", arg[0], arg );
}

int do_check_flower()
{
               object *ob,ob_letter;
               string file ;
               int i;
               ob = users();
               i = sizeof(ob);
               while (i--)
               {
                  if (userp(ob[i]))
                      {

                           file = query_flower_file( ob[i]->query("id")+".o" );
                           assure_file( file );

                                if(file_size(file)!=-1)
                                {

                                        if(interactive(ob[i]))
                                        if(living(ob[i]))
                                        if(!ob[i]-> is_busy())
                                        if(!ob[i]-> is_fighting() )
                                        {
                                                ob_letter=new("/clone/misc/flower");
                                                ob_letter->set_owner(ob[i]->query("id"));
                                                ob_letter->check(ob[i],this_object());
												destruct(ob_letter);
                                        }
                                }
                        }
                }
				  

          remove_call_out("do_check_flower");
          call_out("do_check_flower", 10+random(10) );

          return 1;
}

int ask_songhua()
{
        object ob = this_player();        
        write(CYN"����Ƿ��˵��������л" + RANK_D->query_respect(ob) + "����С�꣬���������ｫ����ã�Ȼ�����СŮҪ�͸�˭��СŮһ��Ϊ���͵���\n"
			  "�ͻ���ʽ��(song ���� to ���ID)��\n"
			  "���ǻ����շѹ����ǣ�ÿһ�仨��ȡһ���ƽ���ͻ��ѡ���\n"NOR);

                
                return 1;
}
int do_song(string arg)
{
	object ob_flower,me,send_flower;
    	int money_amount;
    	mapping flower;
	string flower_name,who;
	me=this_player();
    	if( !arg || sscanf(arg, "%s to %s", flower_name, who)!=2 )
		return notify_fail("��Ҫ��ʲô����˭��\n");
	
	if(!FINGER_D->acquire_login_ob(who))
		  return notify_fail("�������������\n");
	 ob_flower=present(flower_name,me);
     	if(!ob_flower)
        return notify_fail("�����Ϻ���û��������Ʒ��\n");
        if (flower_name == "mms")
        return notify_fail(HIR"��"HIY"��"HIB"��"HIW"'"HIG"��"NOR"�ǳԵĶ�����������ʱ�����͡�\n");
	if(!ob_flower->query("flower_w"))
        return notify_fail("�Բ����������ﲻ�����������\n");
	if(me->is_busy())
		return notify_fail("��������æ���ء�\n");


		if(!send_flower=new("/clone/misc/flower"))
			return notify_fail("/clone/misc/flower��ʼ������,����ʦ��ϵ\n");
		send_flower->set_owner(who);

		if(send_flower->query("flowername")==flower_name)
		  {
			  command("hmm ");
			  return notify_fail("�Բ����һ�û�����ϴεĻ��͵��أ������Ժ������ɡ�\n");
		  }
		
		if(send_flower->query("from")==(me->name(1) + "(" + me->query("id") + ")"))
		  {
			  command("hmm ");
			  return notify_fail("�Բ����һ�û�����ϴεĻ��͵��أ������Ժ������ɡ�\n");
		  }

		/////////////////////////////////////////////////////////////////////////////////
		//******************************�շ�*******************************************//
		if(ob_flower->query_amount()<10)
			money_amount=10;
		else
			money_amount=ob_flower->query_amount();
		
		if(ob_flower->query_amount()>1000)
			money_amount=1000;
		else
			money_amount=ob_flower->query_amount();


		
		switch (MONEY_D->player_pay(me, money_amount*10000) )
		{
	        case 0:  
	        	destruct(send_flower);		
			return notify_fail("������û���㹻��������֧���ͻ����á�\n");
            	case 2: 
            		destruct(send_flower);
			return notify_fail("������Ǯ�����ˣ���Ʊ��û���ҵÿ���\n");
        	}
		message_vision("$N��$n˵������û���⣬�˴��ͻ�������"+MONEY_D->price_str(money_amount*10000)+"����\n",this_object(),this_player());
		////////////////////////////////////////////////////////////////////////////////
		send_flower->set("flowername",ob_flower->query("name"));
		send_flower->set("flower_id",ob_flower->query("id"));
		send_flower->set("to",who);
		send_flower->set("from",me->name(1) + "(" + me->query("id") + ")");
		send_flower->set("amount",ob_flower->query_amount());

		flower = ([
                
		"flowername":ob_flower->query("name"),
            	"flower_id": ob_flower->query("id"),
            	"to": who,
            	"from": me->name(1) + "(" + me->query("id") + ")",
		"amount": ob_flower->query_amount(),

        	]);
		send_flower->send_flower(flower);
		send_flower->save();

		
		message_vision("$n�����ϵ�"+ chinese_number(ob_flower->query_amount()) +ob_flower->query("unit")+flower["flowername"]+"�ó�����$N��\n",this_object(),this_player());
		message_vision("$N��$n˵�������ðɣ�СŮ�Ӷ��Ὣ���͵����������⡣��\n",this_object(),this_player());
		
		destruct(send_flower);
		destruct(ob_flower);
		
		remove_call_out("do_check_flower");
         	call_out("do_check_flower", 10+random(10) );

		return 1;


}
