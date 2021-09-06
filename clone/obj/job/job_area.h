//Cracked by Kafei
//author wzfeng@xkx 2000 6
//xkx_area.h
//���򻮷�
//��ԭ�����֣��䵱������ɽ��̩ɽ���ƺӣ���ɽ
//���ϣ����ݣ����ݣ�̫����Ȫ�ݣ����ˡ�
//�Ͻ����������ң���ɽ��
//�������ޣ����ģ�ѩɽ������ɽ��
//����������ɽ��


//#include "/d/regions.h"
#include "/d/REGIONS.h"
string *zhongyuan=({"shaolin","wudang","zhongnan","tiashan","huanghe","huashan","village"});
string *jiangnan=({"city","hangzhou","taihu","quanzhou","jiaxing"});
string *nanjiang=({"dali","emei","foshan"});
string *xiyu=({"xingxiu","xixia","xueshan","qilian"});
string *dongbei=({"changbai"});
string *cant_go_room=({"/d/taihu/nanfang",
					  "/d/taihu/nvfang",
					  "/d/taihu/liangong",
					  "/d/taihu/chufang",
					  "/d/qilian/dilao"
					  });


/**************************************************************************/
//random get room that on job area
string *get_arearoom(string area)
{
	string *area_list,*filtrate_name,are_name,temp;
	int i;
	mapping room;
    object mapdb;
	mapdb = find_object(MAPDB);
	filtrate_name=({});
	if (! objectp(mapdb))         
		mapdb = new(MAPDB);
	if (! objectp(mapdb))
		return 0;
	switch(area)
	{
	case "��ԭ"   :  
		i=sizeof(zhongyuan);
		are_name=zhongyuan[random(i)];
		
		break;
	case "����"   :  
		i=sizeof(jiangnan);
		are_name=jiangnan[random(i)];
		
		break;
	case "�Ͻ�"   :  
		i=sizeof(nanjiang);
		are_name=nanjiang[random(i)];
		
		break;
	case "����"   :  
		i=sizeof(xiyu);
		are_name=xiyu[random(i)];
		
		break;
	case "����"   :  
		i=sizeof(dongbei);
		are_name=dongbei[random(i)];
		
		break;

		default  : 
			are_name="";
			//break;
			return 0;
	}
	
	//printf("��ѡȡ����Ϊ\t%s\n",are_name);
	//Get all room map.
	room=mapdb->query_map();
	area_list=keys(room);
	if(!area_list)
		return 0;
	//printf("һ����%d������",sizeof(area_list));
	for(i=0;i<sizeof(area_list);i++)
	{
		//we judge which directory matching with area.
		temp=(explode(area_list[i],"/")[1]);
		if(temp==are_name)
		{
			filtrate_name=add_string(area_list[i],filtrate_name);
//			printf("filtrate_name������\t%s\n",area_list[i]);
		}
	}
	if(!i=sizeof(filtrate_name))
	{
		//printf("filtrate_name=0\n");
		return 0;
	}
	for(i=0;i<sizeof(filtrate_name);i++)
	{
		//printf("\t%s\n",filtrate_name[i]);
	}
//	printf("���������%d������\n",sizeof(filtrate_name));
//	filtrate_name=filter_array(filtrate_name, (:filter_room:));
//	printf("���������˺���%d������\n",sizeof(filtrate_name));
	        

	if(!are_name=filtrate_name[random(i)])
		{
	//printf("are_name=0\n");
		return 0;
	}

	//return are_name;
	return filtrate_name;
}
//������ѡȡ�ķ����Ƿ�Ϻ�������
int judge_room(string room_name)
{
	string area;
	object room;
	int ret;
	if(!room_name)
		return 0;
	if (strsrch(room_name, "/d/beijing/")==0 ||
        strsrch(room_name, "/d/island/")==0 ||
        strsrch(room_name, "/d/taohua/")==0 ||
        strsrch(room_name, "/d/shenlong/")==0 ||
        strsrch(room_name, "/d/wizard/")==0 ||
		strsrch(room_name, "/d/huashan/hsforest")==0 ||
		strsrch(room_name, "/d/shaolin/shulin")==0 ||
		strsrch(room_name, "/d/qilian/xiaolu")==0 ||
		strsrch(room_name, "/d/bwdh")==0 ||
        strsrch(room_name, "/d/xiakedao/")==0) return 0;
	
	if(is_attribute(room_name,cant_go_room))
		return 0;

	if(!room=find_object(room_name))
		room=load_object(room_name);
	if(!objectp(room))
		return 0;
	if(room->query("no_fight")
		||!room->query("outdoors"))
		return 0;
	return 1;
}


//get room file name from area
string get_room(string area)
{
	string *area_roomname,are_name;
	int ret,i;;
	ret=0;
	
	area_roomname=get_arearoom(area);

    while ( ret < 10 && ! sizeof(area_roomname)) {
   	ret++;
    area_roomname=get_arearoom(area);
    }
	if(!area_roomname)
		return 0;
	are_name=area_roomname[random(sizeof(area_roomname))];
   	ret=0;

	while ( ret < 10 && !judge_room(are_name)) {
   	ret++;
	//write(are_name+"���䲻��������\n");
	are_name=area_roomname[random(sizeof(area_roomname))];
    }
	if(!judge_room(are_name))
		are_name=area_roomname[random(sizeof(area_roomname))];


//	write("\nget_room ok\n");
	return are_name;
}
