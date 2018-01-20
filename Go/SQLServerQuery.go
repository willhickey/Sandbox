package main
import (
	"database/sql"
	"fmt"
	"os"
	"bufio"
	"strings"
	_ "github.com/denisenkom/go-mssqldb"
)

func main(){
	reader := bufio.NewReader(os.Stdin)
	fmt.Print("Enter password: ")
	pw, _ := reader.ReadString('\n')
	connectString := "sqlserver://scriptuser:"+ strings.TrimSpace(pw) + "@localhost:1433?database=FtCollins&encrypt=disable"//&connection+timeout=30"
	dbConnection, errdb := sql.Open("mssql", connectString)//`server=localhost:1433/MSSQLSERVER;user id=scriptuser;password=password;encrypt=disable`)
	if errdb != nil {
		fmt.Println(" Error open db:", errdb.Error())
	}
	getRouteSQL := `SELECT TOP 200 r.id, o.latitude olatitude, o.longitude olongitude, d.latitude dlatitude, d.longitude dlongitude
			FROM route r JOIN origin o ON r.originid = o.id
					JOIN destination d ON r.destinationid = d.id
			WHERE Source = 'ors' AND RawDirections IS NULL`

	rows, err := dbConnection.Query(getRouteSQL)
	if err!= nil {
		fmt.Println("Error querying db:", err.Error())
	}
	for rows.Next(){
		var (
				id int
				originLat string
				originLon string
				destLat string
				destLon string
			)
		rows.Scan(&id, &originLat, &originLon, &destLat, &destLon)
		fmt.Printf("%d, %s, %s, %s, %s\n", id, originLat, originLon, destLat, destLon)
	}
}