
int do_sign(string arg)
{
   mapping fam;
   int i,j ;
   object *list;   
   object me, where, ling, target; 
   string *ah,word; 
   me = this_player();

 
if(!arg )       
       return notify_fail("你对着空气比划了一阵，旁边的人都莫名其妙的看着你。\n");

if(arg =="fail"&& me->query_temp("party_job")) {
     ling = present("shimen mixin", me);
     if( ling && ling->query("party_job") == me->query("id"))
            destruct(ling);
    
      me->delete_temp("party_job");
      me->delete_temp("party_job_target");
      me->delete_temp("party_job_start");
      me->delete_temp("party_job_over"); //给奖励需要间隔的，如果是持续不触发，那放弃的时候这个也要销毁
      me->apply_condition("job_busy", 3+random(4));
      me->add("combat_exp", -(240+random(130)));
message_vision(HIC"$N微微比了个手势，冲着旁边的小二哥轻轻的摇了摇头。\n"NOR,me);
      return 1;  

                 }
//这里的删除用总开关控制吧。



if(arg =="start"){
	
        fam= me->query("family");
    if ( !fam )    
      	   return notify_fail("你对着空气比划了一阵，旁边的人都莫名其妙的看着你。\n");
    if ( me->query_condition("killer"))
          return notify_fail("你现在是官府捉拿的要犯，还是小心为妙。\n");
    if (me->query("job_name") == "师门贡献"|| me->query_temp("party_job"))            
    	   return notify_fail("你冲小二哥比了个手势，却沮丧的发现他正忙着招呼别人呢，没空理你。\n");
    if ( me->query_condition("job_busy"))
    	   return notify_fail("你冲小二哥比了个手势，却沮丧的发现他正忙着招呼别人呢，没空理你。\n");


if( fam["family_name"] =="少林派" )
        list = filter_array(livings(),(:!userp($1) && ( $1->query("family/family_name") =="少林派" ) && (!$1->query("no_party_job")) && (!$1->query_temp("party_job_target")) :));

if( fam["family_name"] =="华山派" )
        list = filter_array(livings(),(:!userp($1) && ( $1->query("family/family_name") =="华山派" ) && (!$1->query("no_party_job")) && (!$1->query_temp("party_job_target")) :));

if( fam["family_name"] =="神龙教" )
        list = filter_array(livings(),(:!userp($1) && ( $1->query("family/family_name") =="神龙教" ) && (!$1->query("no_party_job")) && (!$1->query_temp("party_job_target")) :));

if( fam["family_name"] =="武当派" )
        list = filter_array(livings(),(:!userp($1) && ( $1->query("family/family_name") =="武当派" ) && (!$1->query("no_party_job")) && (!$1->query_temp("party_job_target")) :));

if( fam["family_name"] =="大轮寺" )
        list = filter_array(livings(),(:!userp($1) && ( $1->query("family/family_name") =="大轮寺" ) && (!$1->query("no_party_job")) && (!$1->query_temp("party_job_target")) :));

if( fam["family_name"] =="峨嵋派" )
        list = filter_array(livings(),(:!userp($1) && ( $1->query("family/family_name") =="峨嵋派" ) && (!$1->query("no_party_job")) && (!$1->query_temp("party_job_target")) :));

if( fam["family_name"] =="姑苏慕容" )
        list = filter_array(livings(),(:!userp($1) && ( $1->query("family/family_name") =="姑苏慕容" ) && (!$1->query("no_party_job")) && (!$1->query_temp("party_job_target")) :));

if( fam["family_name"] =="昆仑派" )
        list = filter_array(livings(),(:!userp($1) && ( $1->query("family/family_name") =="昆仑派" ) && (!$1->query("no_party_job")) && (!$1->query_temp("party_job_target")) :));

if( fam["family_name"] =="全真教" )
        list = filter_array(livings(),(:!userp($1) && ( $1->query("family/family_name") =="全真教" ) && (!$1->query("no_party_job")) && (!$1->query_temp("party_job_target")) :));

if( fam["family_name"] =="日月神教" )
        list = filter_array(livings(),(:!userp($1) && ( $1->query("family/family_name") =="日月神教" ) && (!$1->query("no_party_job")) && (!$1->query_temp("party_job_target")) :));

if( fam["family_name"] =="桃花岛" )
        list = filter_array(livings(),(:!userp($1) && ( $1->query("family/family_name") =="桃花岛" ) && (!$1->query("no_party_job")) && (!$1->query_temp("party_job_target")) :));

if( fam["family_name"] =="天龙寺" )
        list = filter_array(livings(),(:!userp($1) && ( $1->query("family/family_name") =="天龙寺" ) && (!$1->query("no_party_job")) && (!$1->query_temp("party_job_target")) :));

if( fam["family_name"] =="铁掌帮" )
        list = filter_array(livings(),(:!userp($1) && ( $1->query("family/family_name") =="铁掌帮" ) && (!$1->query("no_party_job")) && (!$1->query_temp("party_job_target")) :));

if( fam["family_name"] =="星宿派" )
        list = filter_array(livings(),(:!userp($1) && ( $1->query("family/family_name") =="星宿派" ) && (!$1->query("no_party_job")) && (!$1->query_temp("party_job_target")) :));

if( fam["family_name"] =="丐帮" )
        list = filter_array(livings(),(:!userp($1) && ( $1->query("family/family_name") =="丐帮" ) && (!$1->query("no_party_job")) && (!$1->query_temp("party_job_target")) :));

if( fam["family_name"] =="嵩山派" )
        list = filter_array(livings(),(:!userp($1) && ( $1->query("family/family_name") =="嵩山派" ) && (!$1->query("no_party_job")) && (!$1->query_temp("party_job_target")) :));

if( fam["family_name"] =="逍遥派" )
        list = filter_array(livings(),(:!userp($1) && ( $1->query("family/family_name") =="逍遥派" ) && (!$1->query("no_party_job")) && (!$1->query_temp("party_job_target")) :));

if( fam["family_name"] =="灵鹫宫" )
        list = filter_array(livings(),(:!userp($1) && ( $1->query("family/family_name") =="灵鹫宫" ) && (!$1->query("no_party_job")) && (!$1->query_temp("party_job_target")) :));

  if (!j= sizeof(list) )   return notify_fail(HIG"你冲小二哥比了个手势，小二哥看了你一眼，轻轻的摇了摇头。\n"NOR);

        target = list[random(sizeof(list))];
     
        where = environment(target);
        me->apply_condition("job_busy",15);


        where = environment(target);
        target->set_temp("party_job_target",me->query("id") ); 
        target->apply_condition("clear_party_job",12);
        me->set_temp("party_job_target",target->query("name") ); 
        me->set_temp("party_job",target->query("id") ); 



//任务干脆用ling来控制算了，便于增加内容。
//不同的情况，clone不同的ling来给玩家
//任务标记和状态也一起修改了。便于记忆
//npc反正都是要筛选，现在就是如何处理$1->query不能赋值的问题了。



switch( random(3) ) {
 case 0: {
        ling  = new("quest/party/mixin");

        tell_object(me, "你冲小二比了个手势,小二神色一动，也悄悄的给你比了个手势。\n");
        tell_object(me, "小二趁别人不注意，偷偷塞给你一封密信。\n");
        tell_object(me, HIG"我派"+HIR+target->query("name")+HIW+"("+target->query("id")+")"+HIG"于"+HIC+where->query("short")+HIG+"处遇险，火速驰援，不得有误！\n");
          }
                break;

 case 1: {
       ling  = new("quest/party/mixin");

       tell_object(me, "你冲小二比了个手势,小二神色一动，也悄悄的给你比了个手势。\n");
       tell_object(me, "小二趁别人不注意，偷偷塞给你一封密信。\n");
       tell_object(me, HIG"疑我派"+HIR+target->query("name")+HIW+"("+target->query("id")+")"+HIG"与外敌勾结，欲对师门不利，速去"+HIC+where->query("short")+HIG+"处调查之，\n"NOR);
       tell_object(me, HIR"如有异动，格杀勿论！\n"NOR);
         }
                break;



 case 2: {
        ling  = new("quest/party/mixin");

        tell_object(me, "你冲小二比了个手势,小二神色一动，也悄悄的给你比了个手势。\n");
        tell_object(me, "小二趁别人不注意，偷偷塞给你一封密信。\n");
        tell_object(me, HIG"我派「"+HIR+target->query("name")+HIW+"("+target->query("id")+")"+HIG"」有紧急消息回报师门，速去"+HIC+where->query("short")+HIG+"处接应。\n"NOR);
         }
                break;
                             }

        ling  ->set("party_job_target",target->query("id"));
        ling ->set("party_job",me->query("id"));   //这个也是为了失败的时候来消灭令，捡到别人的令来消灭？也有可能的。
        ling ->move(me);

return 1;
}
else 
       return notify_fail("你对着空气比划了一阵，旁边的人都莫名其妙的看着你。\n");
}