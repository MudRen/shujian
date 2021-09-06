string ask_wdjiuyang()
{
        object me=this_player();
        if (me->query("family/family_name") != "武当派")
                return RANK_D->query_respect(me)+"与本派素无来往，不知此话从何谈起？";

/*
        if (me->query("age",1) > 16)
        	command("knock "+me->query("id"));
		return "我像你这般大时，比你聪明多了。";
*/	

        if (me->query("shen") <0 )
		return "你又去哪干坏事了？";
if (me->query("quest/wdjiuyang/pass"))
	       return "你还没学会吗？";

if (me->query("combat_exp")<5000000 || me->query("int")<33 || me->query("kar")<28 )
	       return "你还是抓紧时间去练功去吧。";


if (me->query_temp("wdjiuyang_ask"))
 return "没完没了地问个什么？";
if (me->query("quest/wdjiuyang/fail") > 3 && !me->query("buyvip"))
return "依你的资质，这项绝学就不要打算了";

//武功学习之间需要间隔一天
 if(me->query("quest/wdjiuyang"+"time") && time()-me->query("quest/wdjiuyang"+"time")<86400)
        {
          command("shake "+me->query("id"));
command("say 你一天问那么多次，也不怕累着？QUEST对你就那么重要啊？");
return "歇歇吧";
  }
me->set_temp("wdjiuyang_ask",1);

me->set("quest/wdjiuyang"+"time",time());
	return "人生如过眼云烟，再回首已是百年身。\n"
        "我先问你几个问题，你只需回答(answer)出答案即可。\n"
        "准备好了吗？(answer yes/no)。\n";

     // 迷魂药，根本没有arg,回答y or n无所谓，这里其实就是提示玩家该answer 了。

}
int questions(object me)
{
	string answer;
if (me->query_temp("wdjiuyang/question")>10) 
{
  command("say 不错不错，那我就告诉你一些往事吧。");
// me->set("quest/wdjiuyang"+"time",time());
    me->set_temp("wdjiuyang1",1);
me->delete_temp("wdjiuyang/question");
remove_call_out("meet");
	call_out("meet", 3);
return 1;
}                


command("say 请回答。");

switch (random(11)) {
		case 0:
			command("say 当年郭大侠的长女名叫什么？");
			answer = "郭芙";
			break;
		case 1:
			command("say 当年郭大侠的小女名叫什么？");
			answer = "郭襄";
			break;
		case 2:
			command("say 我的授业恩师名叫什么？");
			answer = "觉远";
			break;
		case 3:
			command("say 我少年时的名字叫做什么？");
			answer = "张君宝";
			break;

               case 4:
			command("say 郭二小姐在少室山山道之上吟诵的词，词牌名叫什么？");
			answer = "无俗念";
			break;
               case 5:
			command("say 无色禅师在寺中的职务是什么？");
			answer = "罗汉堂首座";
			break;
              case 6:
			command("say 我那觉远师父因何受罚？");
			answer = "经管不慎";
			break;
               case 7:
			command("say 无色禅师交给郭二小姐的诗笺从何而来？");
			answer = "罗汉堂上降龙罗汉佛像的手中";
			break;

               case 8:
			command("say 何足道自创的要弹给郭二小姐的琴曲，由哪两首古风融合而来？");
			answer = "考槃蒹葭";
			break;
               case 9:
			command("say 我少年时，少林寺方丈是何人？");
			answer = "天鸣";
			break;
               case 10:
			command("say 当年我以什么招式连接昆仑三圣三招？");
			answer = "偏花七星";
			break;








}
	this_object()->set("answer",answer);
	return 1;
}

int meet(object me)
{
me = this_player();
tell_object(me,CYN"\n张三丰缓缓说道：“当年我还年幼......”\n"NOR);   
tell_object(me,CYN"\n你听着张三丰的故事，渐渐入了迷，仿佛身临其境一般。\n"NOR);  
remove_call_out("meet1");
        call_out("meet1", 4, me);
        return 1;
}
// 今天先写到这，未完待续。。。by hongba 2012 1.21 凌晨1:32

int do_answer(string arg)
{
	object me = this_player();
	
	if (!arg)
		return notify_fail("你要回答什么？\n");
 if( (int)me->is_busy() || me->is_fighting()) 
return notify_fail("你正忙着呢，别急，慢慢答\n");  // 为防止flood answer，加busy，九阴那里也应该加上
if (me->query_temp("wdjiuyang1"))
return notify_fail("够了，不用再回答了。\n");
if(!me->query_temp("wdjiuyang_ask"))
return notify_fail("你似乎是想找BUG牟利？替洪八CUT你一半EXP！\n");

	if (arg != this_object()->query("answer")) {
		
		command("shake " + me->query("id")); 
 me->start_busy(random(3));
	}
	else {
		command("say 嗯，没错，你很好。");
me->start_busy(random(3));
		

		me->add_temp("wdjiuyang/question",1); 
	}

me->start_busy(random(3));
	call_out("questions", 1, me);
	return 1;
}
int meet1(object me)
{
me = this_player();
tell_object(me,WHT"\n朦胧之中，你仿佛来到了一处所在......\n"NOR);  
me->move("/kungfu/class/wudang/shijie");
return 1;
}


int ask_wdjiuyang1()
{
        object me=this_player();
object ob = this_object();

if(!me->query_temp("wdjiuyang4"))
{
command("say 你问这个做什么?");
return 1;
}
if (me->query("quest/wdjiuyang/fail") > 3 && !me->query("buyvip"))
{
command("say 依你的资质，我看这项功夫就别做打算了。");
return 1;
}

me->set_temp("quest/wdjiuyang/ask",1);
 me->delete_temp("wdjiuyang4");
command("pat "+me->query("id"));
 message_vision(HIC"\n\n$n当年觉远师父念诵这些句子，其实我也未能完全领悟，只能告诉你这么多，剩下了看你的造化罢。\n"NOR,me,ob); 
remove_call_out("thinkingjy");
call_out("thinkingjy",5, me, ob);
tell_object(me,WHT"你拼命地回忆张三丰的话，开始认真思索着.........\n"NOR);
    me->start_busy(2);
          return 1;
}

int thinkingjy(object me, object ob)
{
        int p;
        int i,j=0;
                object* ppl;

        if(!me) return 0;

        ppl= users();

  if(me->query_temp("wdjiuyang_thinking")<(3+random(3)))
        {
                me->add_temp("wdjiuyang_thinking",1);
    if(random(2)) tell_object(me,HIG"\n你努力地回忆刚才张三丰的话,只觉得头昏脑装...\n"NOR);
    else tell_object(me,HIY"\n突然间，你似乎抓到了什么，你努力地回忆刚才张三丰的话，你似乎体会到了其中的变化所在...\n"NOR);
          tell_room(environment(me),HIC""+me->query("name")+"似乎在思索着什么，一副愁眉不展的样子。\n"NOR, ({}));
remove_call_out("thinkingjy");
call_out("thinkingjy",3+random(3), me, ob);
        }
        else
        {
    me->delete_temp("wdjiuyang_thinking");

        p=random(200);
i = sizeof(ppl);
while(i--){
 if( userp(ppl[i])&& !wizardp(ppl[i])&&!ppl[i]->query("no_pk")&& ppl[i]->query("quest/wdjiuyang/pass"))
        j++;

}

//j<=3
        if(p ==7 &&random( me->query("kar"))>28 && me->query("kar")<31 && j<=3 )
    {
       tell_object(me,HIG"\n你此时生怕将刚才体会到的东西忘了，当即盘膝坐下，一字一句地认真记忆。\n"NOR);
       tell_object(me,HIG"\n你当兴之所至，便起身试演几手。也不知过了多少时候，才将那些经书的话语烂记在胸。\n");
       tell_object(me,HIG"\n你只觉扬波搏击，雁飞雕振，延颈协翼，势似凌云，全身都是轻飘飘的，有如腾云驾雾一般。\n");
       message_vision(HIC"\n$N「哈哈哈」大笑几声，说道：“原来如此，原来如此。”\n"NOR,me); 
tell_object(me,HIR"你听了张三丰的指点,终于领悟了武当九阳功的一些要领，剩下的就要自己参悟了。\n"NOR);
       me->set("quest/wdjiuyang/pass",1);
       me->delete_temp("quest/wdjiuyang/ask");
       me->set_skill("wudang-jiuyang",1);
        log_file("quest/wdjiuyang", sprintf(HIR"%s(%s) 成功解开武当九阳。富源：%d；经验：%d。\n"NOR, me->name(1),me->query("id"), me->query("kar"),me->query("combat_exp")) );
    }
    else
    {
       tell_object(me,HIG"\n你脑海里似乎抓住了什么，可是依然不是很明白。\n"NOR);
       message_vision(HIC"\n$N摇了摇头，道：“好像还是很困难的。”说罢，深深地叹了口气。\n"NOR,me); 
       command("poor "+me->query("id"));
       me->add("quest/wdjiuyang/fail",1);
               log_file("quest/wdjiuyang", sprintf(HIR"%s(%s) 解武当九阳失败。富源：%d；经验：%d。\n"NOR, me->name(1),me->query("id"), me->query("kar"),me->query("combat_exp")) );
    }
  }
  return 1;
}


