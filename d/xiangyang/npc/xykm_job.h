// xykm_job.h

#define DEBUG_MODE 0

string xykm_job()
{
	object me = this_player();
	int max,i;
	object obj1;
	object *ob_list;
	object ob2;
//	if (!wizardp(me))	
//              return "暂时关闭,开放日期另行通知!";
	if ( me->query_temp("xykm_job") )
		return "你不是已经接过任务了吗？";
	
	ob_list = filter_array(children(USER_OB), (: clonep($1) && !wizardp($1) :));
	max=sizeof(ob_list);
	for (i=0;i<max;i++){
		obj1 = ob_list[i];
		if (obj1->query_temp("xykm_job") )
		return "这个任务我已经交给" + obj1->query("name")
		+"("+capitalize(obj1->query("id"))+")"+"去做了。";
	}
//调试
	if( !wizardp(me) && !DEBUG_MODE ) {
	if ( me->query_condition("job_busy") || me->query_condition("xykm_job_busy"))
		return "您上次任务辛苦了，还是先休息一下再说吧。";

	if (me->query("job_name") == "襄阳抵御蒙古大军")
		return "您上次任务辛苦了，还是先休息一下再说吧。";
/*		
	if( me->query_temp("xykm_job") )
		return "我这里现在没有什么任务可以给你。";*/
//调试
	}

	ob2 = new("/clone/npc/zhong-shentong");
	if( ob2 ){
		destruct(ob2);
	}
			
	command("say 应郭大侠的邀请，我在这里广邀中原各派武林高手在玄武门抵抗蒙古军队的攻击。\n" );

	set_temp("xykm_job",1);

	// 调试信息
	me->set_temp("xykm_job/asked",1);
	me->apply_condition("job_busy", 30);
	command("say 玄武门是蒙古进犯襄阳的必经之地，你速邀几名武林高手去抵御蒙古军队攻击。\n");
	CHANNEL_D->do_channel( this_object(), "rumor",sprintf(HIR"%s开始襄阳城抵抗蒙古大军任务！", me->name(1)));

	if (wizardp(me)) {
		me->apply_condition("xykm_job", 6);
		me->set("neili", me->query("max_neili")*2);
	}
	else
		me->apply_condition("xykm_job", 10);

	return "蒙古军队不乏有许多高手，你多带弟子，布下阵法，以策万全，切记切记。";
}
