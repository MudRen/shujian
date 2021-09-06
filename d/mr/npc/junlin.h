string ask_junlin()
{
        object me=this_player();
        if (me->query("family/family_name") != "姑苏慕容")
                return RANK_D->query_respect(me)+"与本派素无来往，不知此话从何谈起？";

if( me->query("family/master_name") != "慕容博" )
return RANK_D->query_respect(me)+"与我无缘，不知此话从何谈起？";
if(me->query("quest/junlin/pass"))
return RANK_D->query_respect(me)+"不是已经掌握君临天下的秘密了么？";
if ( !present("shixi biao", this_player()))
return RANK_D->query_respect(me)+"难道不知君临天下的秘密在大燕国世系表中？";

if(me->query_temp("quest/junlin/ask"))
return RANK_D->query_respect(me)+"难道不知君临天下的秘密在大燕国世系表中!";
if(me->query("quest/junlin/fail") > 3)
return RANK_D->query_respect(me)+"看来今生与这绝技无缘!";

//武功学习之间需要间隔一天
 if(me->query("quest/junlin"+"time") && time()-me->query("quest/junlin"+"time")<86400)
        {
          command("shake "+me->query("id"));
command("say 你一天问那么多次，也不怕累着？QUEST对你就那么重要啊？");
return "歇歇吧";
  }

// me->set("quest/junlin"+"time",time());
me->set_temp("quest/junlin/ask",1);
return "大燕国自先祖慕容皝、慕容垂至慕容泓、慕容德，个个英雄豪杰，君临天下。";

}

int accept_object(object me, object obj)
{
if(me->query("quest/junlin"+"time") && time()-me->query("quest/junlin"+"time")<86400)
        {
command("say 你一天问那么多次，也不怕累着？QUEST对你就那么重要啊？");
return 0;
}
if(me->query("quest/junlin/pass"))
{
command("say 你不是已经掌握君临天下的秘密了么？");
return 0;
}
if(me->query("quest/junlin/fail") > 3)
{
command("say 看来你今生与这绝技无缘。");
return 0;
}

if(obj->query("owner")!=me->query("id"))
{
command("say 你从哪弄来的这东西？");
return 0;
}
if(obj->query("id") == "shixi biao" && me->query_temp("quest/junlin/ask") &&
me->query("family/family_name")=="姑苏慕容")
{
command("say 啊？这便是我大燕国世系表？你可知这世系表中除了记载我大燕历代君王之外，还藏有一个重大秘密？");
me->set("quest/junlin"+"time",time());
me->start_busy(999);  
call_out("destructing", 1, obj);
 remove_call_out("thinking");
           call_out("thinking",3, me );
return 1;
}
 else return 0;
             }

void destructing(object obj)
{
	destruct(obj);
}
int thinking(object me)
{
if(!me) return 0;
tell_object(me,HIG"\n慕容博突地拔地而起，十指连弹，指风激射而去，自上而下，挥洒自如，颇有王者风范。\n"NOR);
command("smile ");
command("say 你可看明白了？");
tell_object(me,HIY"\n你开始认真的回忆慕容博的招式...\n"NOR);
remove_call_out("thinking1");
call_out("thinking1",5, me );
}

int thinking1(object me)
{
  int i;
  if(!me) return 0;
	
  if(me->query_temp("junlin")<(3+random(3)))
    { me->add_temp("junlin",1);
          if(random(2)) tell_object(me,HIG"\n你认真回想着刚才慕容博的一招一式...\n"NOR);
             else tell_object(me,HIY"\n突然间，你似乎抓到了什么...\n"NOR);
	  tell_room(environment(me),HIC""+me->query("name")+"似乎在思索着什么，眉头紧皱。\n"NOR, ({}));
	  remove_call_out("thinking1");
	  call_out("thinking1",3+random(3), me);
	}

else
   {  me->delete_temp("junlin");
     
if( random(me->query("kar"))> 28  && random(15)==1 && me->query("buyvip"))

     {
        tell_object(me,HIM"\n你忽然福至心灵，继而长笑一声，喝道：第二指「剑气碧烟横」！\n"NOR);
    message_vision(HIC"\n$N对如何使用君临天下似乎有些了解了。\n"NOR,me); 
   tell_object(me,HIM"\n紧跟着你又一指隔空点出，正是一招「弹指江山破」！江山如画，红尘如梦，指风如刀！\n"NOR);  
message_vision(HIC"\n慕容博哈哈大笑，我大燕国兴复有望！\n"NOR,me); 
     me->set("quest/junlin/pass", 1);
  
       log_file("quest/junlin", sprintf("%s(%s) 失败%d次成功解开君临天下。富源：%d；经验：%d。",     
          me->name(1),
          me->query("id"), 
          me->query("quest/junlin/fail"),
          me->query("kar"),
          me->query("combat_exp")) );
me->start_busy(1);
     }

    else
    {
       tell_object(me,HIG"\n你沉思许久，不得要领。\n"NOR);
       message_vision(HIC"\n$N摇了摇头，深深地叹了口气。\n"NOR,me); 
      tell_object(me,HBBLU"\n很可惜，你本次尝试君临天下解谜失败！\n"NOR);
   tell_object(me,HBBLU"你目前的经验是" + me->query("combat_exp") + "，现在时间是书剑"+ NATURE_D->game_time() + "，请记录。\n"NOR);
      tell_object(me,HBBLU"你将在间隔24小时后获得下一次机会！。\n\n"NOR);
       me->add("quest/junlin/fail,1");
      
       me->start_busy(1);
  
    }

  }

}
