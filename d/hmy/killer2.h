string *way = ([
	"up",
	"down",
	"west",
	"east",
	"south",
	"north",
	"southeast",
	"southwest",
	"northeast",
	"northwest",
	"southup",
	"southdown",
	"northup",
	"northdown",
	"eastup",
	"eastdown",
	"westup",
	"westdown",
]);
	
int valid_leave(object me, string dir)
{
	int i;
	
	if(me->query("hostage/dotwo")>0 && me->query("hostage/passed_l")>0){
       		for(i=0;i<sizeof(way);i++){
       			if (dir == way[i] && objectp(present("mojiao shashou", environment(me)))){
        			tell_room(environment(me),"ħ��ɱ�ִ�������" + me->name() + "�ȵ���" + RANK_D->query_rude(ob) + "������ȥ��ľ���ȵù�������ء�\n");
        			return 1;
        			break;
               		}
               	}
        }
        return ::valid_leave(me, dir);
}
