inherit __DIR__"dzd_room";

int nokill()
{
        object ob = previous_object(1);

        if (ob == find_object("/cmds/skill/exercise")
        || ob == find_object("/cmds/skill/respirate"))
                return 0;
        return 1;
}

void create()
{
	set("short","С��");
	set("long",@LONG
һֻľ�Ƶ�С��������û���������������ͣ�ں����ϣ��ƺ�һ�����˾�
������򷭡�
LONG
	);
	set("objects",([
		__DIR__"npc/npc_dzd" : 1,
		]));
	set("no_fight",(: nokill:) );
}

void run_sea()
{
	tell_room(this_object(),"ͻȻһλ����Ծ��С�������־�Ȼʮ�ֽý������ֱ�����ê����������֮���㿪�˳�ȥ��\n");
	tell_room(this_object(),"��ֻ����һ����ͷת��\n");
	set("long",@LONG
һֻľ�Ƶ�С�����������������ȥ��
LONG
	);	
}

void move_to_iland()
{
	remove_call_out("to_iland");
	call_out("to_iland",3+random(3));
}

void goiland(object me)
{
	me->move(__DIR__"matou");
	tell_room(me,"������ֻ��ֻ�������������İ������ͷ��\n��ͷһ����С���Ѿ���û��\n");
}
void to_iland()
{
	object* obs;
	int t;
	tell_room(this_object(),"�����Ѿ�ײ������ͷ������бб������˲ʱ��Ҫ���ˡ�\n");
	obs = all_inventory(this_object());
	obs = filter_array(obs,(:userp:));
	t = sizeof(obs);
	if(!t) return;
	if(t>10) t= 10;
	for(int i=0;i<t;i++) goiland(obs[i]);
	call_out("to_iland",3+random(3));
}