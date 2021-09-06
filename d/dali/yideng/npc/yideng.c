// yideng.c 一灯大师 By River@SJ 2002.6.6

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

int ask_hr();
int ask_qiu();
int ask_xtg();

void create()
{
	set_name("一灯大师", ({ "yideng dashi", "yideng", "dashi" }) );
	set("title",HIW"南帝"NOR);
	set("gender", "男性" );
	set("class", "bonze");
	set("age", 78);
	set("str", 35);
	set("con", 40);
	set("dex", 35);
	set("int", 35);
	set("per", 28);
	set("unique", 1);

	set("max_qi", 12000);
	set("max_jing", 7500);
	set("eff_jingli", 8500);
	set("neili", 22000);
	set("max_neili", 22000);
	set("jiali", 150);
	set("combat_exp", 4900000);
	set("score", 20000);

	create_family("天龙寺", 12, "俗家弟子");

	set("long", "一个身穿粗布僧袍，两道长长的白眉从眼角垂了下来，面目慈祥，\n"+
		"眉间虽隐含愁苦，但一番雍容高华的神色，却是一望而知。\n");

	set("combat_exp", 4900000);

	set_skill("parry", 400);
	set_skill("dodge", 380);
	set_skill("qingyan-zhang", 380);
	set_skill("strike", 380);
	set_skill("buddhism",200);
	set_skill("force", 400);
	set_skill("literate", 250);
	set_skill("sword", 180);
	set_skill("duanjia-jianfa", 380);
	set_skill("cuff", 200);
	set_skill("axe",200);
	set_skill("pangen-fu",380);
	set_skill("duanjia-quan", 400);
	set_skill("yiyang-zhi", 400);
	set_skill("finger", 400);
	set_skill("qiantian-yiyang", 400);
	set_skill("tianlong-xiang", 400);

	map_skill("dodge", "tianlong-xiang");
	map_skill("parry", "duanjia-jianfa");
	map_skill("sword", "duanjia-jianfa");
	map_skill("force", "qiantian-yiyang");
	map_skill("cuff", "duanjia-quan");
	map_skill("strike", "qingyan-zhang");
	map_skill("finger","yiyang-zhi");
	prepare_skill("finger","yiyang-zhi");
	
	
	set("inquiry", ([
		"here": "这里便是石屋。",
		"黄蓉": (: ask_hr :),
       "慈恩": (: ask_qiu :),
      	"一阳指": (: ask_xtg :),
//    	"学习": (: ask_quest :),
	]));

	setup();
	carry_object("/d/tls/obj/jiasha")->wear();
	carry_object("/d/tls/obj/sengxie")->wear();
}

void attempt_apprentice(object ob)
{
	if ( ob->query_skill("qiantian-yiyang",1) < 180 ){
		command ("hmm");
		command ("say 你乾天一阳功如此之差，我可不收你！");
		return;
	}
	if( ob->query_int(1) < 34){
		command("say 武学之道必须悟性高，依我看" + RANK_D->query_respect(ob) + "的资质似乎不够？");
		return;
	}
	if(ob->query("shen") < 0){
		command("say 大理乃堂堂皇室，而这位" + RANK_D->query_respect(ob) + "眼露凶光，我看不适合在我大理呆下去了。");
		return;
	}
	if(ob->query_skill("liumai-shenjian", 1)){
		command("say 这位" + RANK_D->query_respect(ob) +"已经学会了六脉神剑，不再适合拜我为师了。");
		return;
	}
/*
	if (ob->query("tls")) {
		command ("say 你已经是天龙寺出家弟子了，我不能再收你了！");
		return;
	}
*/
	command("smile");
	command("say 很好，" + RANK_D->query_respect(ob) + "多加努力，他日必定有成。");
	command("recruit " + ob->query("id") );
	ob->delete("tls");
	ob->delete("class");
	ob->set("title",HIW"大理国南帝传人"NOR);
}

int ask_hr()
{
	object me= this_player();
	if (me->query_temp("quest/jindaoheijian/huangrong3")!=1) {
		command("say 小姑娘还好吧？");
		command("haha");
		return 1;
	}

	command("say 都20多年了，裘千尺还记着呢。");
	command("say 不知道我能帮忙吗？");
	message_vision(WHT"你将在黄蓉求见大师的请求告诉了一灯大师!\n"NOR,me); 
	command("say 好吧，你先去绝情谷，我随后就带慈恩就去。");
	command("say 哎！冤冤相报何时能了！");
	me->delete_temp("quest/jindaoheijian/huangrong3");
	me->set_temp("quest/jindaoheijian/yideng",1);
	return 1;
}

int ask_qiu()
{   
    object me= this_player();
    if (me->query("quest/tzauto/pass")|| me->query("family/family_name")!="铁掌帮")
                 {   
                    command(" say 慈恩心愿已了，不愿再沾染尘世之事，施主请回吧。");
                    return 1;
                  }
    command("say 近来风声频传，说道蒙古大军久攻襄阳不下，发兵绕道南攻大理，以便回军迂回，还拔襄阳。\n");
    command("say 慈恩见老衲心念故国，出去打探消息，已经两天两夜没回来了。\n");
     me->set_temp("quest/tzauto/yideng",1); 
  return 1;

}

 int accept_object(object me, object ob)
 
  {
 if( ob->query("id") == "lingwen" 
      && me->query("family/family_name")=="全真教"
      && me->query_temp("quanzhen/force") 
      && !me->query("quanzhen/force")    )
   	   {
               command("ah ");
               command("say 想不到有生之年还能目睹重阳真人的手迹。 "); 
               me->delete_temp("quanzhen/force");
  message_vision(HIM"一灯大师看着手中的《五篇灵文另》，沉默了半响，不由得深深叹了一口气，讲出一段尘封多年的往事来。\n"NOR+
                          HIG"原来当年华山论剑之后，重阳真人对南帝段王爷的一阳指甚为佩服，第二年就和他师弟南下大理，与南帝互相切磋功夫。\n"+
                               "南帝将一阳指的要旨诀窍，尽数说给了重阳真人知道，重阳真人十分喜欢，竟将他最厉害的先天功功夫传给了段王爷。\n"+
                               "重阳真人临别之际言道：“近来我旧疾又发，想是不久人世，好在先天功已有传人，再加上皇爷的一阳指神功，世上已\n"+
                               "有克制蛤蟆功之人，就不怕他横行作怪了。“ \n"NOR, me);
               command("say 那时老衲方才明白，重阳真人千里迢迢来到大理，主旨是要将先天功传给老衲，要在他身死之后，留下一个克制西毒欧阳锋之人。 ");         
               command("sigh ");     
           
               me->set_temp("xtg1",1);
               me->set("give_book",1);
         call_out("destructing", 1, ob); 
                return 1; 
      }
   else return 0;
             }

int ask_xtg()
{
	object me= this_player();
	if (!me->query_temp("xtg1")&& !me->query("give_book")) {
		command("say 一阳指是我大理段家的家传绝技。");
		return 1;
	}

if( me->query("quanzhen/force")== "pass")
{   command("say 看样子小友已经完全掌握了一阳指的要旨诀窍了。");
  me->set("title",HIR"全真教掌教"HIR" "HIC"先天功传人"NOR);
      command("haha ");
return 1;
}
if( (me->query("combat_exp") - me->query("xtg/dyz/exp") <100000 && !me->query("cw_exp")) ||  me->query("quanzhen/force")== "try"   )
	{
				command("say 看样子小友还得多加练习才行。");
						return 1;
		}

   if( time()-me->query("xtg/dyz/time")<86400)		
   		{
				command("say 小友还是去休息一下吧。");
						return 1;
		}

	command("say 重阳真人学到一阳指后，在世不久，并未研习，听说也没传给徒弟。");
    command("say 老衲年事已高，想来也活不了多久了。听说西毒欧阳锋已有传人，当世之上，唯先天功和一阳指两大神技才能克制蛤蟆功。");
    command("say 既然你得到了重阳真人的先天功精要，老衲便将这一阳指传授给你，你当精心研习，勿要让西毒传人横行于世。");


     message_vision(HIY"一灯大师左掌抚胸，右手食指点出，来势虽缓，$N上半身正面大穴却已全在一指笼罩之下，竟不知要点的是那一处穴道，九处大穴皆大指之虞！\n"NOR+
                        HIG"一灯大师招数未完，抢上数步，又是一指点出，这次却是指向$N小腹，这一指所盖罩的要穴更广，肚腹间冲脉十二大穴，自幽门\n"+
                               "通谷，下至中注、四满，直抵横骨、会阴，尽处于这一指威力之下。\n"+
                        HIM"跟着一灯大师第三指又出，这一指迅如闪电，直指$N眉心，指尖闪动，似乎头部太阳，人中，百会．．等各大要穴尽在这一指笼罩。 \n"NOR, me);
    command("smile ");
    command("say 你可看明白了？");
me->delete_temp("xtg1");
 tell_object(me,HIY"\n你开始认真的回忆一灯大师的一招一式。。\n"NOR);
       me->start_busy(999);              
       remove_call_out("thinking");
           call_out("thinking",5, me );

	return 1;
}



int thinking(object me)
{
  int i,j,total;
  if(!me) return 0;
	
  if(me->query_temp("try_yyz")<(3+random(3)))
    { me->add_temp("try_yyz",1);
          if(random(2)) tell_object(me,HIG"\n你认真回想着刚才一灯大师的一招一式...\n"NOR);
             else tell_object(me,HIY"\n突然间，你似乎抓到了什么...\n"NOR);
	  tell_room(environment(me),HIC""+me->query("name")+"似乎在思索着什么，眉头紧皱。\n"NOR, ({}));
	  remove_call_out("thinking");
	  call_out("thinking",3+random(3), me);
	}

else
   {  me->delete_temp("try_yyz");


j = 25;
if(me->query("m-card-vip")) j =  22;
if(me->query("y-card-vip")) j =  20;
if(me->query("buyvip"))     j =  15;
i=random(j);

if (i == 10 && random(me->query("kar"))>=28 )
{
        tell_object(me,HIM"\n你先天功真气由膻中，入缺盆，过阳池外关，交与三焦手少阳之脉，一呼一吸，引而不发，在体内流转不休！\n"NOR);
    message_vision(HIC"\n$N对如何使用一阳指指法驱动先天功内力似乎有些了解了。”\n"NOR,me); 
     tell_object(me,HIR"你对如何使用一阳指指法驱动先天功内力似乎有些了解了，剩下的就是勤加练习了！\n"NOR);
     me->set("quanzhen/force", "try" );
  me->set("title",HIC"全真教先天功传人"NOR);
       log_file("quest/quanzhen/force", sprintf("%s(%s) 失败%d次成功解开定阳针。富源：%d；经验：%d。\n",   
          me->name(1),
          me->query("id"), 
          me->query("xtg/dyz/fail"),
          me->query("kar"),
          me->query("combat_exp")) );
me->start_busy(1);
     }

    else
    {
       tell_object(me,HIG"\n你沉思许久，不得要领。\n"NOR);
       message_vision(HIC"\n$N摇了摇头，深深地叹了口气。\n"NOR,me); 
      tell_object(me,HBBLU"\n很可惜，你本次尝试先天功定阳针秘密失败！\n"NOR);
   tell_object(me,HBBLU"你目前的经验是" + me->query("combat_exp") + "，现在时间是书剑"+ NATURE_D->game_time() + "，请记录。\n"NOR);
      tell_object(me,HBBLU"你将在间隔24小时并增加100K实战经验后获得下一次机会！。\n\n"NOR);
       me->add("xtg/dyz/fail",1);
       me->set("xtg/dyz/exp", me->query("combat_exp") );
       me->start_busy(1);
  me->set("xtg/dyz/time",time());
    }

  }

}

