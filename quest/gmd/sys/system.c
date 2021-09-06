varargs void make_killer(object me,int boss)
{
	        object killer;

                  if(!me) return;
if ( me->query_temp("/quest/gmd/hongshui"))
{
killer =new("quest/gmd/npc/tang");

killer->move(environment(me));
}
else if ( me->query_temp("/quest/gmd/liehuo"))
{
killer =new("quest/gmd/npc/xin");
killer->move(environment(me));
}
else if ( me->query_temp("/quest/gmd/houtu"))
{
killer =new("quest/gmd/npc/yan");
killer->move(environment(me));
}
else if ( me->query_temp("/quest/gmd/ruijin"))
{
killer =new("quest/gmd/npc/zhuang");
killer->move(environment(me));
}
else if ( me->query_temp("/quest/gmd/jumu"))
{
killer =new("quest/gmd/npc/wen");
killer->move(environment(me));
}
}
