// qzkj_job.h

#define DEBUG_MODE 0

string qzkj_job()
{
	object me = this_player();
	int max,i;
	object obj1;
	object *ob_list;
	object ob2;
//	if (!wizardp(me))	
              return "目前战事比较平静，没听说过有金兵进犯。你还是先请回吧!";
	if ( me->query_temp("qzkj_job") )
		return "你不是已经接过任务了吗？";
	
	ob_list = filter_array(children(USER_OB), (: clonep($1) && !wizardp($1) :));
	max=sizeof(ob_list);
	for (i=0;i<max;i++){
		obj1 = ob_list[i];
		if (obj1->query_temp("qzkj_job") )
		return "这个任务我已经交给" + obj1->query("name")
		+"("+capitalize(obj1->query("id"))+")"+"去做了。";
	}
//调试
	if( !wizardp(me) && !DEBUG_MODE ) {
	if ( me->query_condition("job_busy") || me->query_condition("qzkj_job_busy"))
		return "您上次任务辛苦了，还是先休息一下再说吧。";

	if (me->query("job_name") == "全真教抗击金兵")
		return "您上次任务辛苦了，还是先休息一下再说吧。";
/*		
	if( me->query_temp("qzkj_job") )
		return "我这里现在没有什么任务可以给你。";
*/		
//调试
	}

	ob2 = new("/clone/npc/zhong-shentong");
	if( ob2 ){
		destruct(ob2);
	}
		
	//GIFT_D->check_count(me,this_object(),"颂摩崖");
			
	command("say 我刚才接到我教弟子尹志平报告，完颜洪烈派遣大批高手来攻击我全真教。\n" );

	set_temp("qzkj_job",1);

	// 调试信息
	me->set_temp("qzkj_job/asked",1);
	me->apply_condition("job_busy", 30);
	command("say 中天门是金兵进犯我全真教的必经之地，你速带几名弟子埋伏在那里截杀。\n");
	CHANNEL_D->do_channel( this_object(), "rumor",sprintf(HIR"%s开始全真教抗击金兵任务！", me->name(1)));

	if (wizardp(me)) {
		me->apply_condition("qzkj_job", 6);
		me->set("neili", me->query("max_neili")*2);
	}
	else
		me->apply_condition("qzkj_job", 10);

	return "这批武士中不乏高手，你多带弟子，布下阵法，以策万全，切记切记。";
}
