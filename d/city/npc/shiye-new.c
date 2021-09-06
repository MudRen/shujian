// shiye.c modified by fengyue 2008.10.19

#include <ansi.h>
#define JADE    "/d/zhiye/obj/othermaterial" //玉
#define KUANGSHI    "/d/zhiye/obj/kuangshi" //矿
#define BULIAO    "/d/zhiye/obj/buliao" //布料

inherit NPC;
int ask_me(object who);

void create()
{
	set_name("王坏水", ({ "wang huaishui", "wang" }));
	set("title", "从九品师爷");
	set("gender", "男性");
	set("age", 57);
	set("combat_exp", 30000);
	set_skill("unarmed", 50);
	set_skill("dodge", 60);
	set_temp("apply/attack",  20);
	set_temp("apply/defense", 20);
	set_temp("apply/damage",  20);
	set("shen", -1);
	set("inquiry", ([
//                 "俸禄" : (: ask_me :),
	]));
	setup();
	carry_object("/clone/armor/cloth")->wear();
	carry_object("/clone/armor/shoes")->wear();
}

int ask_me(object who)
{
        object me = this_player();
        object obj;
        int times,gold,gold2,gold3,tb2,exp,tb,exp1;

        string str = "";
       int i = random(3);
        times = (int)me->query("job_time/官府",1);

        if ( times<49 ){
		command("say 你没为朝廷出过什麽力，还想要俸禄？\n");
		return 1;
	}
        if ( times > 15000 ){
		command("say 在下不过是个知府师爷，怎麽还敢给您发俸禄呢？\n");
		command("flatter " + me->query("id"));
		return 1;
        }


if( (int)me->query("gf_gives") < (int)me->query("age") && time()- me->query("gf_job_time")>604800 ) 
{

    exp = times * 1500;
    exp1 = times * 1000;
    gold=times * ( 50 + random(30) );
    gold2=gold/10000;
    gold3=gold/20000;
    tb = random(times /50) + 1; 
    tb2 = random(times /50)+1; 
me->set("gf_job_time",time());

if (me->query_temp("mark/huilu"))
           {
			command("hehe " + me->query("id"));
                        message_vision("王坏水点头哈腰的说道，这位"+RANK_D->query_respect(me)+"辛苦了, 以后还望多多关照在下。\n",me);
	//		command("give "+me->query("id")+" gold");
			me->delete_temp("mark/huilu");
                        me->set("gf_gives",(int)me->query("age"));

                        me->add("balance", gold);
                        me->add("SJ_Credit", tb );
                        me->add("combat_exp", exp);

                 message_vision(HIC"王坏水拿出一张刑部行文递给"+me->query("name")+"说：这是刑部发我扬州官员年度俸禄行文,这位"+RANK_D->query_respect(me)+",你自己看吧。\n",me);
                 switch(i) {
                        case 0:         
                                obj = new (KUANGSHI);
                                obj->set_level(8+random(2));
               
                                break;    
                         case 1:         
                                 obj = new (BULIAO);
                                obj->set_level(8+random(1));
               
                                break;   
                                 
                         case 2:         
                                obj = new (JADE);
                                
                                        obj->set("secret_obj",1);
                                        obj->set_level(4+random(1));
                                        str = "极品";
                                
                                str += "玉";  
                                break;   
                                break;  
                        default:return 1;
                           }
                           obj->move(me);
    
              message_vision(HIC""+me->query("name")+""HIC"今年应得俸禄为黄金" + CHINESE_D->chinese_number(gold2) + "锭,通宝" + CHINESE_D->chinese_number(tb) + "个。\n"NOR, me);  
              tell_object(me,HIY"特别嘉奖『"+obj->name()+""HIY"』一"+obj->query("unit")+"。\n"NOR);
              tell_object(me,HIY"你获得了" + CHINESE_D->chinese_number(exp) + "点经验奖励！\n"NOR);



              if(times >= 5000 && random(10) > 5 )
{
  message_vision(HIC"由于"+me->query("name")+""HIC"工作勤奋，成绩斐然，获得年度『"HIR"江湖神捕"HIC"』称号，威名大增！\n"NOR, me);  
  tell_object(me,HIY"你额外获得了" + CHINESE_D->chinese_number(exp) + "点经验奖励！\n"NOR);
                      me->add("combat_exp", exp);
                      me->set("title", HIR"江湖神捕"NOR);


}



			return 1;
	}

//如果不给他贿赂
		command("look " + me->query("id"));
		command("hmm " + me->query("id"));
		command("say 等下，让我看一看！\n");
           
             message_vision(WHT"王坏水装模作样的拿出一张刑部批文看了看。\n"NOR, me);
    message_vision(HIC"王坏水说道："+me->query("name")+"今年应得俸禄为黄金" + CHINESE_D->chinese_number(gold3) + "锭,通宝" + CHINESE_D->chinese_number(tb2) + "个。\n"NOR, me); 
                        me->add("balance", gold/2);
                        me->add("SJ_Credit", tb2);
                        me->add("combat_exp", exp1);

 tell_object(me,HIY"你获得了" + CHINESE_D->chinese_number(exp1) + "点经验奖励！\n"NOR);
		
 message_vision(WHT""+me->query("name")+"隐约觉得数目好象不大对啊。\n"NOR, me);
		me->set("gf_gives",(int)me->query("age"));
		return 1;
	}

        command("say 没到时间呢，领什麽俸禄？!\n");

        return 1;
}

int accept_object(object me, object obj)
{
        int times;
        times=me->query("job_time/官府",1);

        if (!me->query("job_time/官府")){
		command("say 无缘无故送礼，想贿赂我？\n");
		return 1;
        }
        if(obj->query("money_id")){
                if(obj->value() >= times*10){
			command("hehe "+me->query("id"));
			command("whisper "+me->query("id")+" 你就放心吧，回头我会好好关照你的！");
			me->set_temp("mark/huilu",1);
			return 1;
		}
		command("say 这么点钱能干什麽？还不够我去一次丽春院的呢？");
		return 1;
        }
	command("say 拿这个"+obj->name()+"来给我，有什麽用？！");
	return 0;
}

void destroy (object obj)
{
	destruct(obj);
	return;
}
